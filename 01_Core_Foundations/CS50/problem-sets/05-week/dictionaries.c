// Implements a dictionary's functionality

#include "dictionary.h"
#include <ctype.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <string.h>

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
} node;

// TODO: Choose number of buckets in hash table
const unsigned int N = 26;
unsigned int S = 0;

// Hash table
node *table[N];

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    int word_hash = hash(word);
    //   for (node *ptr = list; ptr != NULL; ptr = ptr->next)

    for (node *p = table[word_hash]; p != NULL; p = p->next)
    {
        if (strcasecmp(word, p->word) == 0)
        {
            return true;
        }
    }
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO: Improve this hash function
    return toupper(word[0]) - 'A';
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    FILE *input_dict = fopen(dictionary, "r");
    if (input_dict == NULL)
    {
        printf("Cant find file %s!\n", dictionary);
        return false;
    }
    char new_word[LENGTH + 1];
    while (fscanf(input_dict, "%s", new_word) !=
           EOF) // returns EOF when end of file, was not explained >:(
    {
        printf("-> %s\n", new_word);
        node *new_node = malloc(sizeof(node));
        if (new_node == NULL)
        {
            printf("Cant allocate node\n");
            return false;
        }
        strcpy(new_node->word, new_word);
        new_node->next = NULL;
        unsigned int hashed_word = hash(new_word);
        if (table[hashed_word] == NULL)
        {
            table[hashed_word] = new_node;
        }
        else
        {
            node *current_node = table[hashed_word];
            new_node->next = current_node;
            table[hashed_word] = new_node;
        }
        S += 1;
    }

    fclose(input_dict);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    return S;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    for (unsigned int i = 0; i < N; i++)
    {
        node *current = table[i];
        while (current != NULL)
        {
            node *tmp = current;
            current = current->next;
            free(tmp);
        }
    }
    return true;
}

