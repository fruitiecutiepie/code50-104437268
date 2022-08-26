import os

from cs50 import SQL
from flask import Flask, flash, redirect, render_template, request, session
from flask_session import Session
from tempfile import mkdtemp
from werkzeug.security import check_password_hash, generate_password_hash

from helpers import apology, login_required, lookup, usd

# Configure application
app = Flask(__name__)

# Ensure templates are auto-reloaded
app.config["TEMPLATES_AUTO_RELOAD"] = True

# Custom filter
app.jinja_env.filters["usd"] = usd

# Configure session to use filesystem (instead of signed cookies)
app.config["SESSION_PERMANENT"] = False
app.config["SESSION_TYPE"] = "filesystem"
Session(app)

# Configure CS50 Library to use SQLite database
db = SQL("sqlite:///finance.db")

# !!! DELETE WHEN SUBMITTING
API_KEY = "pk_7fae8605ca2848c99c97f7fbfbac4acf"

# Make sure API key is set
if not os.environ.get("API_KEY"):
    raise RuntimeError("API_KEY not set")


@app.after_request
def after_request(response):
    """Ensure responses aren't cached"""
    response.headers["Cache-Control"] = "no-cache, no-store, must-revalidate"
    response.headers["Expires"] = 0
    response.headers["Pragma"] = "no-cache"
    return response


@app.route("/")
@login_required
def index():
    """Show portfolio of stocks"""
    return render_template("index.html", cash=db.execute("SELECT cash FROM users WHERE id = ?", session["user_id"]), portfolios=db.execute("SELECT symbol, shares FROM portfolios WHERE user_id = ?", session["user_id"]))


@app.route("/buy", methods=["GET", "POST"])
@login_required
def buy():
    """Buy shares of stock"""

    # User reached route via POST (as by submitting a form via POST)
    if request.method == "POST":

        # Get response
        symbol = request.form.get("symbol")
        shares = request.form.get("shares")

        # Look up quote for symbol
        quote = lookup(symbol)

        # Look up cash
        cash = db.execute("SELECT cash FROM users WHERE id = ?", session["user_id"])

        # Calculate total purchase
        total = quote["price"] * shares

        # Ensure symbol was submitted
        if not symbol:
            return apology("must provide symbol", 403)

        # Ensure symbol exists
        if not quote:
            return apology("symbol not found", 403)

        # Ensure shares was submitted
        if not shares or shares < 1:
            return apology("must provide a positive number of shares", 403)

        # Ensure user has enough cash
        if cash < total:
            return apology("must have enough cash", 403)

        # Add stock to portfolio
        stock_shares = db.execute("SELECT shares FROM portfolios WHERE user_id = ? AND symbol = ?",
                                   session["user_id"], symbol)
        if stock_shares:
            db.execute("UPDATE portfolios SET shares = ? WHERE user_id = ? AND symbol = ?",
                       (stock_shares + shares), session["user_id"], symbol)
        else:
            db.execute("INSERT INTO portfolios (user_id, symbol, shares) VALUES (?, ?, ?)",
                        session["user_id"], symbol, shares)

        # Update cash
        db.execute("UPDATE users SET cash = ? WHERE id = ?",
                   (cash - total), session["user_id"])

        # Record purchase
        db.execute("INSERT INTO history (user_id, symbol, bought, purchase_price) VALUES (?, ?, ?, ?)",
                    session["user_id"], symbol, shares, quote["price"])

        # Show user portfolio
        return redirect("/")

    # User reached route via GET (as by clicking a link or via redirect)
    else:
        return render_template("buy.html")


@app.route("/history")
@login_required
def history():
    """Show history of transactions"""
    return render_template("index.html", history=db.execute("SELECT * FROM history WHERE user_id = ?", session["user_id"]))


@app.route("/login", methods=["GET", "POST"])
def login():
    """Log user in"""

    # Forget any user_id
    session.clear()

    # User reached route via POST (as by submitting a form via POST)
    if request.method == "POST":

        # Ensure username was submitted
        if not request.form.get("username"):
            return apology("must provide username", 403)

        # Ensure password was submitted
        elif not request.form.get("password"):
            return apology("must provide password", 403)

        # Query database for username
        rows = db.execute("SELECT * FROM users WHERE username = ?", request.form.get("username"))

        # Ensure username exists and password is correct
        if len(rows) != 1 or not check_password_hash(rows[0]["hash"], request.form.get("password")):
            return apology("invalid username and/or password", 403)

        # Remember which user has logged in
        session["user_id"] = rows[0]["id"]

        # Redirect user to home page
        return redirect("/")

    # User reached route via GET (as by clicking a link or via redirect)
    else:
        return render_template("login.html")


@app.route("/logout")
def logout():
    """Log user out"""

    # Forget any user_id
    session.clear()

    # Redirect user to login form
    return redirect("/")


@app.route("/quote", methods=["GET", "POST"])
@login_required
def quote():
    """Get stock quote."""

    # User reached route via POST (as by submitting a form via POST)
    if request.method("POST"):

        # Ensure symbol was submitted
        if not request.form.get("symbol"):
            return apology("must provide symbol", 403)

        # Ensure symbol exists
        if not lookup(request.form.get("symbol")):
            return apology("symbol not found", 403)

        # Display the results
        return render_template("quoted.html", stock=lookup(request.form.get("symbol")))

    # User reached route via GET (as by clicking a link or via redirect)
    else:
        return render_template("quote.html")


@app.route("/register", methods=["GET", "POST"])
def register():
    """Register user"""

    # User reached route via POST (as by submitting a form via POST)
    if request.method == "POST":

        # Ensure username was submitted
        if not request.form.get("username"):
            return apology("must provide username", 403)

        # Ensure password was submitted
        elif not request.form.get("password"):
            return apology("must provide password", 403)

        # Ensure password was confirmed
        elif not request.form.get("confirmation"):
            return apology("must provide password confirmation", 403)

        # Ensure password and password confirmation confirmed
        elif request.form.get("password") != request.form.get("confirmation"):
            return apology("passwords must match", 403)

        # Query database for username
        rows = db.execute("SELECT * FROM users WHERE username = ?", request.form.get("username"))

        # Ensure username has not been taken
        if len(rows) != 0:
            return apology("username has been taken", 403)

        # Generate a hash of the password for security
        hash = generate_password_hash(request.form.get("password"))

        # Add user to database
        db.execute("INSERT INTO users (username, hash) VALUES (?, ?)", request.form.get("username"), hash)

        # Remember which user has logged in
        session["user_id"] = db.execute("SELECT id FROM users WHERE username = ?", request.form.get("username"))

        # Redirect user to look up stock quotes
        return redirect("/quote")

    # User reached route via GET (as by clicking a link or via redirect)
    else:
        return render_template("register.html")


@app.route("/sell", methods=["GET", "POST"])
@login_required
def sell():
    """Sell shares of stock"""

    # User reached route via POST (as by submitting a form via POST)
    if request.method == "POST":

        # Get response
        symbol = request.form.get("symbol")
        shares = request.form.get("shares")

        # Calculate total sale
        total = lookup(symbol)["price"] * shares

        # Ensure symbol was submitted
        if not symbol:
            return apology("must provide symbol", 403)

        # Ensure symbol exists
        if not lookup(symbol):
            return apology("symbol not found", 403)

        # Ensure symbol is in user's portfolio
        if not symbol in db.execute("SELECT symbol FROM portfolios WHERE id = ?", session["user_id"]):
            return apology("symbol must be in portfolio", 403)

        # Ensure shares was submitted
        if not shares or shares < 1:
            return apology("must provide a positive number of shares", 403)

        # Ensure number of sold shares was valid
        stock_shares = db.execute("SELECT shares FROM portfolios WHERE symbol = ? AND id = ?", symbol, session["user_id"])
        if shares > stock_shares:
            return apology("number of shares overboard", 403)

        # Sell specified stock
        db.execute("UPDATE portfolios SET shares = ? WHERE symbol = ? AND id = ?",
                    (stock_shares - shares), symbol, session["user_id"])

        # Record purchase
        db.execute("INSERT INTO history (user_id, symbol, sold, sale_price) VALUES (?, ?, -?, ?)",
                    session["user_id"], symbol, shares, quote["price"])

        # Update cash
        cash = db.execute("SELECT cash FROM users WHERE id = ?", session["user_id"])
        db.execute("UPDATE users SET cash = ? WHERE id = ?", (cash + total), session["user_id"])

        # Show user portfolio
        return redirect("/")

    # User reached route via GET (as by clicking a link or via redirect)
    else:
        return render_template("sell.html", symbols=db.execute("SELECT symbol FROM portfolios WHERE id = ?", session["user_id"]))
