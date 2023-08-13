#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define LISTSIZE 1000
#define EXACT 2
#define CLOSE 1
#define WRONG 0

#define GREEN "\e[38;2;255;255;255;1m\e[48;2;106;170;100;1m"
#define YELLOW "\e[38;2;255;255;255;1m\e[48;2;201;180;88;1m"
#define RED "\e[38;2;255;255;255;1m\e[48;2;220;20;60;1m"
#define RESET "\e[0;39m"

string get_guess(int wordsize);
int check_word(char *guess, char *choice, int *status, int wordsize);
void print_word(string guess, int wordsize, int status[]);

int main(int argc, string argv[])
{
    int totalScore = 0; // renamed from score to totalScore
    if (argc != 2)
    {
        printf("Usage: ./wordle wordsize\n");
        return 1;
    }

    int wordsize = atoi(argv[1]);
    if (wordsize < 5 || wordsize > 8)
    {
        printf("Error: wordsize must be either 5, 6, 7, or 8\n");
        return 1;
    }

    char wl_filename[6];
    sprintf(wl_filename, "%i.txt", wordsize);
    FILE *wordlist = fopen(wl_filename, "r");
    if (wordlist == NULL)
    {
        printf("Error opening file %s.\n", wl_filename);
        return 1;
    }

    char options[LISTSIZE][wordsize + 1];
    for (int i = 0; i < LISTSIZE; i++)
    {
        fscanf(wordlist, "%s", options[i]);
    }
    fclose(wordlist);

    srand(time(NULL));
    string choice = options[rand() % LISTSIZE];
    int guesses = wordsize + 1;
    bool won = false;

    printf(GREEN "This is WORDLE50" RESET "\n");
    printf("You have %i tries to guess the %i-letter word I'm thinking of\n", guesses, wordsize);

    for (int i = 0; i < guesses && !won; i++)
    {
        string guess = get_guess(wordsize);
        int status[wordsize];
        memset(status, WRONG, sizeof(status));

        int roundScore = check_word(guess, choice, status, wordsize); // score for this specific round
        totalScore += roundScore;                                     // update the overall score

        printf("Guess %i: ", i + 1);
        print_word(guess, wordsize, status);

        printf(" %d \n", roundScore); // Print the round score

        if (roundScore == wordsize * EXACT)
        {
            won = true;
            printf("You won!\n");
        }
    }

    if (!won)
    {
        printf("Out of tries! The word was: %s\n", choice);
    }

    return totalScore;
}

char *get_guess(int wordsize)
{
    char *guess = NULL;
    do
    {
        guess = get_string("Input a %d-letter word: ", wordsize);
    }
    while (strlen(guess) != wordsize || strspn(guess, "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ") != wordsize);
    return guess;
}

int check_word(char *guess, char *choice, int *status, int wordsize)
{
    int local_score = 0;

    // Check for exact matches
    for (int i = 0; i < wordsize; i++)
    {
        if (guess[i] == choice[i])
        {
            status[i] = EXACT;
            local_score += EXACT;
        }
    }

    // Check for close matches
    for (int i = 0; i < wordsize; i++)
    {
        if (status[i] != EXACT)
        { // If we haven't found an exact match for this letter
            for (int j = 0; j < wordsize; j++)
            {
                // Ensure that it hasn't already been marked as an EXACT match or CLOSE match
                if (guess[i] == choice[j] && status[j] != EXACT && status[i] != CLOSE)
                {
                    status[i] = CLOSE;
                    local_score += CLOSE;
                    break;
                }
            }
        }
    }

    return local_score;
}

void print_word(string guess, int wordsize, int status[])
{
    for (int i = 0; i < wordsize; i++)
    {
        if (status[i] == EXACT)
        {
            printf(GREEN "%c", guess[i]);
        }
        else if (status[i] == CLOSE)
        {
            printf(YELLOW "%c", guess[i]);
        }
        else
        {
            printf(RED "%c", guess[i]);
        }
    }
    printf(RESET "\n");
}
