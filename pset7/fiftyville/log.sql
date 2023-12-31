-- Keep a log of any SQL queries you execute as you solve the mystery.

-- Look for a crime scene report that matches the date and the location of the crime
SELECT description
FROM crime_scene_reports
WHERE year = 2021
AND month = 7
AND day = 28
AND street = 'Humphrey Street';
-- Found: Humphrey Street bakery; 10:15 AM; interviews with three witnesses, each mentioned the bakery.

-- Look for interviews that matches the date and the location of the crime
SELECT transcript
FROM interviews
WHERE year = 2021
AND month = 7
AND day = 28;
-- Found witnesses: Ruth, Eugene, and Raymond.

-- Look for cars that exited the bakery within ten minutes of the theft
SELECT license_plate
FROM bakery_security_logs
WHERE year = 2021
AND month = 7
AND day = 28
AND hour = 10
AND minute BETWEEN 10 AND 20
AND activity = 'exit';
-- Found possible license plate: 5P2BI95, 94KL13X, 6P58WS2, 4328GD8, or G412CB7.

-- Look for ATM transactions on Leggett Street earlier that morning
SELECT account_number, amount
FROM atm_transactions
WHERE year = 2021
AND month = 7
AND day = 28
AND atm_location = 'Leggett Street'
AND transaction_type = 'withdraw';
-- Found 8 possible account numbers.

-- Look for phone calls for < 1 minute as the thief was leaving the bakery -> accomplice
SELECT caller, receiver
FROM phone_calls
WHERE year = 2021
AND month = 7
AND day = 28
AND duration < 60;
-- Found 8 possible phone calls.

-- Look for people with matching license plates and phone numbers
SELECT *
FROM people
WHERE license_plate IN ('5P2BI95', '94KL13X', '6P58WS2', '4328GD8', 'G412CB7')
AND phone_number IN
(
    SELECT phone_number
    FROM people
    WHERE license_plate IN ('5P2BI95', '94KL13X', '6P58WS2', '4328GD8', 'G412CB7')
        INTERSECT
    SELECT caller
    FROM phone_calls
    WHERE year = 2021
    AND month = 7
    AND day = 28
    AND duration < 60
);
-- Found possible thief: Sofia or Bruce; passport number: 1695452385 or 5773159633, respectively.

-- Look for earliest flight out of Fiftyville tomorrow -> 29-7-21
SELECT id, destination_airport_id
FROM flights
WHERE origin_airport_id =
(
    -- Get origin airport ID
    SELECT id
    FROM airports
    WHERE city = 'Fiftyville'
)
AND year = 2021
AND month = 7
AND day = 29
ORDER BY hour
LIMIT 1;
-- Found destination airport ID: 4; flight ID: 36.

-- Look for city the thief escaped to
SELECT city
FROM airports
WHERE id = 4;
-- Found city: New York City [ANSWER]

-- Look for passengers in the flight that matches aforementioned passport numbers
SELECT *
FROM passengers
WHERE flight_id = 36
AND passport_number IN (1695452385, 5773159633);
-- Both Sofia and Bruce are in the same flight. (!)

-- Look for the people who Sofia and Bruce called
SELECT *
FROM people
WHERE phone_number IN
(
    -- Look for the phone numbers of whom Sofia and Bruce called
    SELECT receiver
    FROM phone_calls
    WHERE year = 2021
    AND month = 7
    AND day = 28
    AND duration < 60
    AND caller IN
    (
        SELECT phone_number
        FROM people
        WHERE name IN ('Sofia', 'Bruce')
        INTERSECT
        SELECT caller
        FROM phone_calls
        WHERE year = 2021
        AND month = 7
        AND day = 28
        AND duration < 60
    )
);
-- Found possible accomplice: Jack or Robin; ID: 567218 or 864400, respectively.

-- Look for the ATM transactions Jack and Robin made that day to book the flight (IF ANY).
SELECT *
FROM atm_transactions
WHERE account_number IN
(
    SELECT account_number
    FROM bank_accounts
    WHERE person_id IN (567218, 864400)
)
AND year = 2021
AND month = 7
AND day = 28;
-- Found account number: 69638157; ATM location: Humphrey Lane.

-- Look for people with the aforementioned account number
SELECT *
FROM people
WHERE id =
(
    SELECT person_id
    FROM bank_accounts
    WHERE account_number = 69638157
);
-- Found accomplice: Jack [ANSWER]; phone number = (996) 555-8899

-- Look for the person who called Jack
SELECT *
FROM people
WHERE phone_number =
(
    SELECT caller
    FROM phone_calls
    WHERE receiver = '(996) 555-8899'
    AND year = 2021
    AND month = 7
    AND day = 28
    AND duration < 60
);
-- Found thief: Sofia [ANSWER]


-- Comments on exercise:
-- Very interesting, intriguing, and exciting. Done within one sitting with full focus.
-- Unfortunately, the result of ATM transactions the thief made was not used in the process of solving the mystery.
-- Am curious as to why that was left as one of the trails in one of the interviews' transcripts.
-- Nevertheless, excellent exercise depicting a real use case of the SQL language.
-- Thank you CS50 for this wonderful exercise (and course).
-- Definitely the best one I've had so far!


-- 😱 what? it's incorrect?! there must be something I missed here. interesting.


-- Match the bank account number of Sofia and Bruce with the ATM transactions on Leggett Street
SELECT name
FROM people
WHERE id IN
(
    SELECT person_id
    FROM bank_accounts
    WHERE account_number IN
    (
        SELECT account_number
        FROM bank_accounts
        WHERE person_id IN
        (
            SELECT id
            FROM people
            WHERE name IN ('Sofia', 'Bruce')
        )
            INTERSECT
        SELECT account_number
        FROM atm_transactions
        WHERE year = 2021
        AND month = 7
        AND day = 28
        AND atm_location = 'Leggett Street'
        AND transaction_type = 'withdraw'
    )
);
-- Turns out only Bruce had a bank account.
-- Found thief: Bruce [NEW ANSWER]

-- Look for the person Bruce called
SELECT name
FROM people
WHERE phone_number =
(
    SELECT receiver
    FROM phone_calls
    WHERE caller =
    (
        SELECT phone_number
        FROM people
        WHERE name = 'Bruce'
    )
    AND year = 2021
    AND month = 7
    AND day = 28
    AND duration < 60
);
-- Found thief: Robin [NEW ANSWER]


-- Additional comments on exercise:
-- ok. WE GOT IT BABY
-- Clever. And tricky. One small mistake (simple assumption) could lead to a whole different direction (result).
-- And that very same mistake was the very same one that I questioned in my last comment. Very interesting indeed.
-- The danger and responsibilities of working as a detective--a meticulous person is required indeed.
-- Thanks to check50, innocent people were not mistreated.
-- And thank you for the unexpected plot twist, made it even more fun.