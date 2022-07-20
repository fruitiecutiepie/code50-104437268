# TODO

# Prompt user for card number
while True:
    num = input("Number: ")
    if re.match("", num);
        break

# Prepare total for Luhn's algorithm to determine validity
total = 0

# Multiply every other digit by 2,
# starting with the number’s second-to-last digit,
# and then add those products’ digits together
for i in range(len(num)-2, -1, -2):
    mult = int(num[i]) * 2
    for j in str(mult):
        total += int(j)

# Add the sum to the sum of the digits that weren’t multiplied by 2
for i in range(len(num)-1, -1, -2):
    total += int(num[i])

# Print output according to each card number
if str(total)[-1] == '0':
    if len(num) == 15 and num[:2] == '34' or num[:2] == '37':
        print("AMEX")
    if len(num) == 16 and num[:2] == '51' or num[:2] == '52' or \
            num[:2] == '53' or num[:2] == '54' or num[:2] == '55':
        print("MASTERCARD")
    if len(num) == 13 or len(num) == 16 and num[0] == '4':
        print("VISA")
else:
    print("INVALID")