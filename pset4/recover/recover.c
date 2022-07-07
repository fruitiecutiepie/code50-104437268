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
    int counter = 0;

    // Read input file until the end
    while (fread(buffer, 1, BLOCK_SIZE, file) == BLOCK_SIZE)
    {
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            counter++;
            filename 
            sprintf(filename, %03i.jpg, counter);
        }
    }
}