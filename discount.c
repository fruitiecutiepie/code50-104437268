#include <cs50.h>
#include <stdio.h>

float discount(float price);

int main(void)
{
    float reg = get_float("Regular Price: ");
    float sale = discount(reg);
    printf("Sale Price: %.2f\n", sale);
}

float discount(float price)
{
    return price * .85;
}