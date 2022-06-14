#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    long credit_num, mod, digit;

    // Prompt user for a credit card number
    do
    {
        credit_num = get_long("Number: ");
    }
    while (credit_num > LONG_MAX);

    // Convert credit card number to string
    string credit_len = (string) credit_num;

    for (mod = 100; mod < credit_num; mod *= 100)
    {
        digit = credit_num % mod;
        string second_last_digit = (string) digit;
        printf("%s\n", second_last_digit);
    }
}