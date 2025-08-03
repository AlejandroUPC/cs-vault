#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    for (int i = 0; argv[1][i] != '\0'; i++)
    {
        if (!isdigit(argv[1][i]))
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
    }

    int key = atoi(argv[1]);
    string user_word = get_string("plaintext: ");

    int len = strlen(user_word);
    char new_word[len + 1];

    for (int i = 0; i < len; i++)
    {
        if (isupper(user_word[i]))
            new_word[i] = ((user_word[i] - 'A' + key) % 26) + 'A';
        else if (islower(user_word[i]))
            new_word[i] = ((user_word[i] - 'a' + key) % 26) + 'a';
        else
            new_word[i] = user_word[i];
    }

    new_word[len] = '\0';
    printf("ciphertext: %s\n", new_word);
    return 0;
}

