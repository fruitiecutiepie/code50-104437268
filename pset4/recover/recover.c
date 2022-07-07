#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    if (argc != 1)
    {
        printf("Usage: ./recover IMAGE\n");
        return 1;
    }

    if (FILE *file = fopen(argv[1], "r") == NULL)
    {
        printf("File cannot be opened.\n");
        return 2;
    }
}