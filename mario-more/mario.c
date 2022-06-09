#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int height, k, space, hash;
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

    // Return left side of pyramid
    // For each row
    for (k = 0; k < height; k++)
    {
        for (space = height; space > 0; space--)
        {
            printf(".");
        }

        // For each column
        for (hash = 0; hash <= k; hash++)
        {
            printf("#");
        }
        printf("\n");
    }
}