#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int height, i, j, k, l;
    do
    {
        height = get_int("How tall do you want the pyramid to be? [1-8] ");
    }
    while (height < 1 || height > 8);



    // Return invisible space
    // For each row
    for (i = height; i > 0; i--)
    {
        // For each column
        for (j = 0; j < i; j++)
        {
            printf(".");
        }

        // Return left side of pyramid
        // For each row
        //for (k = 0; k < height; k++)
        //{
            // For each column
            //for (l = 0; l <= k; l++)
            //{
                //printf("#");
            //}
        //}

        printf("\n");
    }
}