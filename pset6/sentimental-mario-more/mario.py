# TODO
from cs50 import get_int

height = get_int("Height: ")
while height > 8 and height < 1:
    height = get_int("Height: ")