# TODO
from cs50 import get_int

# Prompt user for a positive integer between 1 & 8, inclusive
while True:
    height = get_int("Height: ")
    if height > 0 and height < 9:
        break

for i in range(1, height + 1):
    # Print left whitespace
    for j in range(height - i, 0, -1):
        print(" ", end="")

    # Print left pyramid
    print("#" * i, end="")

    # Print middle whitespace
    print("  ", end="")

    # Print right pyramid
    print("#" * i)