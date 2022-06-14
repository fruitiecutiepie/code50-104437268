#include <cs50.h>
#include <stdio.h>

int main(void)
{
    long credit_num, mod;
    // Prompt user for a credit card number
    do
    {
        credit_num = get_long("Number: ");
    }
    while (credit_num > LONG_MAX);

    for (mod = 100; mod < len(credit_num); mod * 100)
    {
        printf(credit_num % mod);
    }
}