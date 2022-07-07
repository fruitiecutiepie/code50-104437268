#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    // Make sure there is only one command-line argument
    if (argc != 1)
    {
        printf("Usage: ./recover IMAGE\n");
        return 1;
    }

    // Open input file
    FILE *file = fopen(argv[1], "r")
    if (file == NULL)
    {
        printf("File could not be opened.\n");
        return 1;
    }
}