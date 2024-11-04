#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define RPS_OPTIONS 3
#define ROCK 0
#define PAPER 1
#define SCISSORS 2
#define INITIAL_STATUS 4
#define END_COND 999

void GenRandSeed() 
{
    srand((unsigned int)time(NULL));
}

const char* getRPSString(int choice)
{
    switch (choice)
    {
        case ROCK: return "Rock";
        case PAPER: return "Paper";
        case SCISSORS: return "Scissors";
        default: return "Unknown";
    }
}

// main function loop
int main(void)
{
    // assigning seed
    GenRandSeed();

    // initializing variables
    int nComRPS = INITIAL_STATUS;
    int nPlayerRPS = INITIAL_STATUS;

    // infinite loop
    while (1)
    {
        // generating the Player's Status
        printf("Input your choice (Rock:0, Paper:1, Scissors:2);\n");
        printf("If you want to end the loop, please input 999\n");

        // Input from Users
        if (scanf("%d", &nPlayerRPS) != 1)
        {
            // Handling the case where input is not an integer
            printf("Invalid input! Please enter a number.\n");
            while (getchar() != '\n'); // Clear input buffer
            continue;
        }

        // exception #1, end condition
        if (nPlayerRPS == END_COND)
        {
            printf("End of the infinite while loop RPS game...\n");
            break;
        }

        // exception #2, input condition
        if (nPlayerRPS < 0 || nPlayerRPS >= RPS_OPTIONS)
        {
            printf("Check your input condition...\n");
            continue;
        }

        // Computer choice
        nComRPS = (rand() % RPS_OPTIONS);
        printf("You chose: %s\n", getRPSString(nPlayerRPS));
        printf("Computer chose: %s\n", getRPSString(nComRPS));

        // Determine winner
        if (nPlayerRPS == nComRPS)
        {
            printf("It's a tie!\n");
        }
        else if ((nPlayerRPS == ROCK && nComRPS == SCISSORS) ||
                 (nPlayerRPS == PAPER && nComRPS == ROCK) ||
                 (nPlayerRPS == SCISSORS && nComRPS == PAPER))
        {
            printf("You win!\n");
        }
        else
        {
            printf("Computer wins!\n");
        }
    }

    return 0;
}