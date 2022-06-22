#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <strings.h>

int main(int argc, string argv[])
{
    // Validate key
    string key = argv[1];
    int len = strlen(key);

    // Check for one command-line argument
    if (argc != 2 && argc < 2)
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
    for (int i = 0; i < len; i++)
    {
        if (isalpha(key[i]) == 0)
        {
            printf("Key must only contain alphabetic characters.\n");
            return 1;
        }
    }

    // Check for repeated characters (case-insensitive)
    for (int i = 0; i < len; i++)
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

    // Prompt user for plaintext
    string plaintext = get_string("plaintext:  ");

    // Encipher & print ciphertext
    printf("ciphertext: ");
    for (int i = 0, l = strlen(plaintext); i < l; i++)
    {
        if (isalpha(plaintext[i]))
        {
            if (isupper(plaintext[i]))
            {
                printf("%c", toupper(key[plaintext[i] - 65]));
            }
            else
            {
                printf("%c", tolower(key[plaintext[i] - 97]));
            }
        }
        else
        {
            printf("%c", plaintext[i]);
        }
    }
    printf("\n");
}