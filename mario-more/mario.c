#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int height, i, space, hash, j;
    do
    {
        height = get_int("How tall do you want the pyramid to be? [1-8] ");
    }
    while (height < 1 || height > 8);

    // // Return invisible space
    // // For each row
    // for (i = height; i > 0; i--)
    // {
    //     // For each column
    //     for (j = 0; j < i; j++)
    //     {
    //         printf(".");
    //     }
    //     printf("\n");
    // }

    // For each row
    for (i = 0; i < height; i++)
    {
        // For each column

        // Print space
        for (space = height - i; space > 1; space--)
        {
            printf(" ");
        }

        // Print pyramid
        for (hash = 0; hash <= i; hash++)
        {
            printf("#");
        }

        for (j = 2; j)
        {
            printf("..");
        }

        printf("\n");
    }
}