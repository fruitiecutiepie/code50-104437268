#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int height, i, space, hash, j, hash2;
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

        // Print left whitespace
        for (space = height - i; space > 1; space--)
        {
            printf(" ");
        }

        // Print left pyramid
        for (hash = 0; hash <= i; hash++)
        {
            printf("#");
        }

        // Print middle whitespace
        printf("  ");

        // Print right pyramid
        for (hash2 = 0; hash2 <= i; hash2++)
        {
            printf("#");
        }

        // Print newline to show hierarchy
        printf("\n");
    }
}