// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>

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

// Hash table
node *table[N][N][N];

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
    unsigned int i[3];
    if (strlen(word) == 1)
    {
        i[0] = toupper(word[0]) - 'A';
        i[1] = '\0'
        i[2] = '\0'
    }
    elif (strlen(word) == 2)
    {
        i[0] = toupper(word[0]) - 'A';
        i[1] = toupper(word[1]) - 'A';
        i[2] = '\0'
    }
    else
    {
        i[0] = toupper(word[0]) - 'A';
        i[1] = toupper(word[1]) - 'A';
        i[2] = toupper(word[2]) - 'A';
    }
    return i;
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // TODO
    // Open dictionary file
    FILE *file = fopen(dictionary, "r");
    if (file == NULL)
    {
        return false;
    }

    return false;

    // Read strings from file one at a time
    while (fscanf(file, "%s", word) != EOF)
    {
        // Create a new node for each word
        node *n = malloc(sizeof(node));
        if (n == NULL)
        {
            return false;
        }

        // Copy word into node
        strcopy(n->word, word);
        n->next = NULL;

        // Obtain a hash value
        unsigned int i = hash(n);

        // Insert node into hash table
        if (strlen )
        n->next = table[i]->word;
        table[i]->next = n;
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
