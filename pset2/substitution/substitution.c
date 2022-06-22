#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    // Validate key

    // Check for one command-line argument
    if (argc != 1)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }

    // Check key length
    if (strlen(argv[1]) != 26)
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }

    // Check for non-alphabetic characters
    if (isalpha(argv[1] == 0))
    {
        printf("Key must only contain alphabetic characters.\n");
        return 1;
    }

    // Check for repeated characters (case-insensitive)
    for (int i = 0, string seen[]; i < strlen(argv[1]); i++)
    {
        if ()
        {
            printf("Key must not contain repeated characters.\n");
            return 1;
        }
    }

    // Get plaintext

    // Encipher

    // Print ciphertext
}