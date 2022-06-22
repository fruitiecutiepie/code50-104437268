#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <strings.h>

int main(int argc, string argv[])
{
    // Validate key
    string key = argv[1];

    // Check for one command-line argument
    if (argc != 1)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }

    // Check key length
    if (strlen(key) != 26)
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }

    // Check for non-alphabetic characters
    if (isalpha(key == 0))
    {
        printf("Key must only contain alphabetic characters.\n");
        return 1;
    }

    // Check for repeated characters (case-insensitive)
    for (int i = 0, len = strlen(key); i < l; i++)
    {
        for (int j = i + 1; j < len; j++)
        {
            if (key[i] == key[j])
            {
                printf("Key must not contain repeated characters.\n");
                return 1;
            }
        }
    }

    // Get plaintext

    // Encipher

    // Print ciphertext
}