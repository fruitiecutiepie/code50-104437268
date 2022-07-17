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

// Initialize number of words in dictionary
int s = 0;

// Hash table
node *table[N];

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // TODO
    // Obtain a hash value
    unsigned int i = hash(n->word);

    while (table->next != NULL)
    {

    }
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO: Improve this hash function
    if (strlen(word) == 1)
    {
        return (toupper(word[0]) - 'A');
    }
    else
    {
        return (toupper(word[0]) - 'A') * 26 + (toupper(word[1]) - 'A');
    }
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
        if (table[i] == NULL)
        {
            table[i] = n;
        }
        else
        {
            n->next = table[i]->next;
            strcpy(table[i]->word, n->word);
        }

        // Count number of words in dictionary
        s++;
    }
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    return s;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO
    return false;
}
