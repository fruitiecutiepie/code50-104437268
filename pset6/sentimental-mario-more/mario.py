# TODO
from cs50 import get_int

while True:
    height = get_int("Height: ")
    if height != range(1,8):
        height = get_int("Height: ")