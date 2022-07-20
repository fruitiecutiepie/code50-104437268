# TODO
num = input("Number: ")

total = 0

for i in range(len(num)-2, -1, -2):
    mult = int(num[i]) * 2
    for j in str(mult):
        total += int(j)

for i in range(len(num)-1, -1, -2):
    total += int(num[i])

if str(total)[-1] == '0':
    if len(num) == 15 and num[:2] == '34' or num[:2] == '37':
        print("AMEX")
    if len(num) == 16 and num[:2] == '51' or num[:2] == '52' or num[:2] == '53' or num[:2] == '54' or num[:2] == '55':
        print("MASTERCARD")
    if len(num) == 13 or len(num) == 16 and num[0] == '4':
        print("VISA")
else:
    print("INVALID")