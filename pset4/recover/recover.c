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

    typedef uint8_t BYTE;

    int BLOCK_SIZE = 512;
    BYTE buffer[BLOCK_SIZE];

    // Read input file until the end
    while (fread(buffer, sizeof(uint8_t), BLOCK_SIZE, file) == BLOCK_SIZE)
    {

    }
}