#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ATTEMPTS 10
#define RANGE_MIN 1
#define RANGE_MAX 100

// Function to generate a random number within a range
int GenRandNum(int min, int max)
{
    return rand() % (max - min + 1) + min;
}

int main(void)
{
    // Initialize random seed
    srand((unsigned int)time(NULL));

    // Generate a random number for the user to guess
    int targetNumber = GenRandNum(RANGE_MIN, RANGE_MAX);
    int userGuess = 0;
    int attempts = 0;

    printf("Welcome to the Up/Down Game! You have %d attempts to guess the number.\n", MAX_ATTEMPTS);

    // Loop for up to MAX_ATTEMPTS
    while (attempts < MAX_ATTEMPTS)
    {
        printf("Attempt %d: Enter your guess (between %d and %d): ", attempts + 1, RANGE_MIN, RANGE_MAX);
        scanf("%d", &userGuess);

        // Check if the user's guess is correct
        if (userGuess == targetNumber)
        {
            printf("Congratulations! You guessed the correct number: %d\n", targetNumber);
            break;
        }
        else if (userGuess > targetNumber)
        {
            printf("Down! Try a smaller number.\n");
        }
        else
        {
            printf("Up! Try a larger number.\n");
        }

        attempts++;

        // Check if the user has used all attempts
        if (attempts == MAX_ATTEMPTS)
        {
            printf("Game Over! The correct number was: %d\n", targetNumber);
        }
    }

    return 0;
}