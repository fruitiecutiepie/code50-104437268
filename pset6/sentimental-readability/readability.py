# TODO
from cs50 import get_string

text = get_string("Text: ")

letters = 0
words = 1
sentences = 0

for i in text:
    # Count letters
    if text[i].isalpha():
        letters += 1

    # Count words
    if text[i].isspace():
        words += 1

    # Count sentences
    if text[i] == '.' or text[i] == '!' or text[i] == '?':
        sentences += 1

# Average number of letters per 100 words
L = letters / words * 100
# Average number of sentences per 100 words
S = sentences / words * 100

# Calculate readability based on the Coleman-Liau index
index = 0.0588 * L - 0.296 * S - 15.8
grade = round(index)

if grade >= 16:
    print("Grade 16+")
elif grade < 1:
    print("Before Grade 1")
else:
    print(f"Grade {grade}")