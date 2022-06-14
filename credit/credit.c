#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // Prompt user for a credit card number
    do
    {
        long credit_num = get_long("Number: ");
    }
    while (credit_num > LONG_MAX);
}