#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main(int argc, char *argv[])
{
    // Check for one command-line argument
    if (argc != 2)
    {
        printf("Usage: ./recover IMAGE\n");
        return 1;
    }

    // Open input file
    FILE *file = fopen(argv[1], "r");
    if (file == NULL)
    {
        printf("File could not be opened.\n");
        return 1;
    }

    int BLOCK_SIZE = 512;
    uint8_t buffer[BLOCK_SIZE];
    int counter = 0;
    FILE *img;

    // Read input file until the end
    while (fread(buffer, 1, BLOCK_SIZE, file) == BLOCK_SIZE)
    {
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            if (counter == 0)
            {
                // Store formatted output file name in filename
                char *filename = malloc(8);
                sprintf(filename, "%03i.jpg", counter);

                // Open output file
                FILE *img = fopen(filename, "w");

                fwrite(buffer, 1, BLOCK_SIZE, img);

                // Count found JPEGs
                counter++;

                // Free filename memory
                free(filename);
            }
            else
            {
                fclose(img);

                // Store formatted output file name in filename
                char *filename = malloc(8);
                sprintf(filename, "%03i.jpg", counter);

                // Open output file
                FILE *img = fopen(filename, "w");

                fwrite(buffer, 1, BLOCK_SIZE, img);

                // Count found JPEGs
                counter++;

                // Free filename memory
                free(filename);
            }
        }
        else
        {
            if (counter > 0)
            {
                fwrite(buffer, 1, BLOCK_SIZE, img);
            }
        }
    }
    fclose(file);
    fclose(img);
}