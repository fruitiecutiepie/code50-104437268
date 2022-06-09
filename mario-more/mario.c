#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int height, i, j, k;
    do
    {
        height = get_int("How tall do you want the pyramid to be? [1-8] ");
    }
    while (height < 1 || height > 8);

    // For each row
    for (i = height; i > 0; i--)
    {
        // For each column
        for (j = 0; j < i; j++)
        {
            printf(",");
        }

        for (k = 0; k < height; k++)
        {
            printf("#");
        }
        printf("\n");
    }
}