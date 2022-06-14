#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    long credit_num, mod, number;

    // Prompt user for a credit card number
    do
    {
        credit_num = get_long("Number: ");
    }
    while (credit_num > LONG_MAX);

    // Convert credit card number to string
    string credit_len = (string) credit_num;
    //printf("%c", credit_len[0]);
    for (mod = 100; mod < strlen(credit_len); mod *= 100)
    {
        //number = credit_num % mod;
        //printf("%li", number);
    }
}