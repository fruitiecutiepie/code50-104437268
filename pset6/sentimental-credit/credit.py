# TODO
num = input("Number: ")

total = 0

for i in range(len(num)-2, -1, -2):
    mult = num[i] * 2
    for j in mult:
        total += int(j)

print(total)

for i in range(len(num)-1, -1, -2):
    total += int(num[i])

print(total)