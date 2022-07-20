# TODO
num = input("Number: ")

total = 0

for i in range(len(num)-2, -1, -2):
    mult = int(num[i]) * 2
    for j in str(mult):
        total += int(j)

for i in range(len(num)-1, -1, -2):
    total += int(num[i])

if total 