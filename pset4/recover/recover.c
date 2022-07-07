#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    // Check for one command-line argument
    if (argc != 2)
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

    int BLOCK_SIZE = 512;
    
}