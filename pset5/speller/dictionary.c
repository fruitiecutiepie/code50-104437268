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
const unsigned int N = 676;

// Hash table
node *table[N];

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // TODO
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO: Improve this hash function
    int i = 0, n = strlen(word);
    while (i < n)
    {
        if (i == strlen(word) - 1)
        {
            return (toupper(word[i]) - 'A');
        }
        else
        {
            return (toupper(word[i]) - 'A') * 26 + hash(&word[i+1]);
        }
    }
    return 0;
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
        unsigned int i = hash(n->word);

        // Insert node into hash table
        strcpy(table[i]->word, n->word);
        n->next = table[i]->next;
    }
    return true;
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
