#include <stdio.h>
#include <string.h>

//this program takes two words and scores them based off scrabble scoring.

// Points assigned to each letter of the alphabet
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int compute_score(char* word);

int main(int argc, char* argv[])
{
    // Get input words from both players
    char* word1 = argv[1];
    char* word2 = argv[2];

    // Score both words
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);
    

    // TODO: Print the winner
    if (score1 > score2)
    {
        printf("Player 1 wins!\n");
    }
    else
    {
        if (score2 > score1)
        {
            printf("Player 2 wins!\n");
        }
        else
        {
            printf("Tie!\n");
        }
    }
}


int compute_score(char* word)
{
    
    const int lo = strlen(word);
    
    //make all letters uppercase
    for (int i = 0; i < lo; i++)
    {
        if (word[i] > 96)
        {
            word[i] = word[i] - 32;
        }
        else
        {
            word[i] = word[i];
        }
    }
    //compute and return score
    int tot_score = 0;
    for (int i = 0; i < lo; i++)
    {
        //add to tot_score
        int z = (int) word[i];
        tot_score += POINTS[z - 65];
    }
    return tot_score;
}
