#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};
int get_word_points(string word);

int main(void)
{
    string p1_guess = get_string("Player 1: ");
    string p2_guess = get_string("Player 2: ");
    int points_p1 = get_word_points(p1_guess);
    int points_p2 = get_word_points(p2_guess);
    if (points_p1 > points_p2)
    {
        printf("Player 1 wins\n");
    }
    else if (points_p2 > points_p1)
    {
        printf("Player 2 wins\n");
    }
    else
    {
        printf("Tie");
    }
    return 0;
}

int get_word_points(string word)
{
    int total_points = 0;
    for (int i = 0; i < strlen(word); i++)
    {
        if (!isalpha(word[i]))
        {
            continue;
        }
        else
        {
            total_points += POINTS[toupper(word[i]) - 'A'];
        }
    }
    return total_points;
}

