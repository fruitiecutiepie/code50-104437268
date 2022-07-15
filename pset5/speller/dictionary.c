// Implements a dictionary's functionality

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
#include <string.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// TODO: Choose number of buckets in hash table
const unsigned int N = 26;
unsigned int *i[3];

// Hash table
node *table[N][N][N];

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // TODO
    return false;
}

// Hashes word to a number
void hash(const char *word)
{
    // TODO: Improve this hash function
    if (strlen(word) == 1)
    {
        *i[0] = toupper(word[0]) - 'A';
        *i[1] = '\0';
        *i[2] = '\0';
    }
    else if (strlen(word) == 2)
    {
        *i[0] = toupper(word[0]) - 'A';
        *i[1] = toupper(word[1]) - 'A';
        *i[2] = '\0';
    }
    else
    {
        for (int j = 0; j < 3; j++)
        {
            if (word[j] == '\'')
            {
                *i[j] = '\0';
            }
            else
            {
                *i[j] = toupper(word[j]) - 'A';
            }
        }
    }
    return;
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // TODO
    // Open dictionary file
    FILE *file = fopen(dictionary, "r");
    if (file == NULL)
    {
        free(file);
        return false;
    }

    return false;

    // Read strings from file one at a time
    char word[LENGTH + 1];
    while (fscanf(file, "%s", word) != EOF)
    {
        // Create a new node for each word
        node *n = malloc(sizeof(node));
        if (n == NULL)
        {
            free(n);
            return false;
        }

        // Copy word into node
        strcpy(n->word, word);
        n->next = NULL;

        // Obtain a hash value
        hash(n->word);

        // Insert node into hash table
        if (strlen(word) == 1)
        {
            n->next = table[*i[0]]->next;
            table[*i[0]]->word = n;
        }
        else if (strlen(word) == 2)
        {
            n->next = table[*i[0]][*i[1]]->word;
            table[*i[0]][*i[1]]->next = n;
        }
        else
        {
            n->next = table[*i[0]][*i[1]][*i[2]]->word;
            table[*i[0]][*i[1]][*i[2]]->next = n;
        }
    }
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    return 0;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO
    return false;
}
