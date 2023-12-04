// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
} node;

// TODO: Choose number of buckets in hash table
const unsigned int N = 26 * 26 * 26 * 26 * 26;

// Hash table
node *table[N];
unsigned int count = 0;
unsigned int hash_value = 0;

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // TODO
    hash_value = hash(word);
    node *cursor = table[hash_value];

    while (cursor != 0)
    {
        if (strcasecmp(word, cursor->word) == 0)
        {
            return true;
        }
        cursor = cursor->next;
    }
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO: Improve this hash function
    unsigned long total = 0;
    for (int i = 0, l = strlen(word); i < l; i++)
    {
        total += tolower(word[i]);
    }
    return total % N;
    // return toupper(word[0]) - 'A';
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // TODO
    // open the dictionary
    FILE *file = fopen(dictionary, "r");
    if (!file)
    {
        unload();
        return false;
    }

    char word[LENGTH + 1];
    while (fscanf(file, "%s", word) != EOF) // read the dictionary word by word untill reach to the end of the file (EOF)
    {
        node *n = malloc(sizeof(node));
        if (!n)
        {
            return false;
        }
        strcpy(n->word, word);
        n->next = NULL;
        hash_value = hash(word);
        n->next = table[hash_value];
        table[hash_value] = n;
        count++;
    }
    fclose(file);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO

    return count;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO
    for (int i = 0; i < N; i++)
    {
        node *cursor = table[i];

        while (cursor != NULL)
        {
            node *temp = cursor;
            cursor = cursor->next;
            free(temp);
        }
    }
    return true;
}
