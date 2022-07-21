# TODO
from cs50 import get_string

text = get_string("Text: ")

letters = 0
words = 0
sentences = 0

for i in text:
    if text[i].isalpha():
        letters += 1
    if 