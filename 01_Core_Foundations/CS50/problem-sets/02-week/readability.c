#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    string user_text = get_string("Text: ");
    int letter_cter = 0;
    int sentence_cter = 0;
    int word_cter = 1;
    float L;
    float S;
    for (int i = 0; i < strlen(user_text); i++)
    {
        if (isalpha(user_text[i])) // this is a letter
        {
            letter_cter += 1;
        }
        if (user_text[i] == '.' || user_text[i] == '!' || user_text[i] == '?')
        {
            sentence_cter += 1;
        }
        else if (user_text[i] == ' ')
        {
            word_cter++;
        }
    }
    L = ((float) letter_cter / word_cter) * 100;
    S = ((float) sentence_cter / word_cter) * 100;
    float index = ((0.0588 * L) - (0.296 * S) - 15.8);
    if (index < 1.0)
    {
        printf("Before Grade 1\n");
        return 0;
    }
    else if (index > 16.0)
    {
        printf("Grade 16+\n");
        return 0;
    }
    printf("Grade %i\n", (int) (index + 0.5));
}

