#include <cs50.h>
#include <stdio.h>

int main(void)
{
    long credit_num;
    // Prompt user for a credit card number
    do
    {
        credit_num = get_long("Number: ");
    }
    while (credit_num > LONG_MAX);

    for (mod = 10; mod < credit_num; mod * 10)
    {
        
    }
}