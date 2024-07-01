#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_LEN 100

// Points assigned to each letter of the alphabet
int points[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int compute_score(char word[]);

int main(void)
{
    char word1[MAX_LEN], word2[MAX_LEN];

    // Prompting player 1 for their word
    printf("Player 1: ");
    scanf("%s", word1);

    // Prompting player 2 for their word
    printf("Player 2: ");
    scanf("%s", word2);

    // Calculate scores for both words
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    // Determine the winner or if there's a tie
    if (score1 > score2)
    {
        printf("Player 1 wins!\n");
    }
    else if (score2 > score1)
    {
        printf("Player 2 wins!\n");
    }
    else
    {
        printf("Tie!\n");
    }

    return 0;
}

int compute_score(char word[])
{
    int score = 0;

    // Compute the score for the word
    for (int i = 0, len = strlen(word); i < len; i++)
    {
        if (isalpha(word[i]))
        {
            int letter_index = toupper(word[i]) - 'A';
            score += points[letter_index];
        }
    }

    return score;
}
