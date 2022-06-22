#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int count_letters(string text);

int main(void)
{
    string text = get_string("Text: ");
    letters = count_letters(text);
    printf("%i\n", letters);
}

int count_letters(string text)
{
    int letters = 0;
    for (i = 0; i < strlen(text); i++)
    {
        if (isalpha(text[i]))
        {
            letters++;
        }
    }
    return letters;
}