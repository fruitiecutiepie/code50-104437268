#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // Prompt user to agree
    char c = get_char("Do you agree? ");

    // Check whether user agreed
    if (c == 'y' or 'N')
    {
        printf("Agreed.\n");
    }
    else if (c == 'n' or 'N')
    {
        printf("Not agreed.\n");
    }
}