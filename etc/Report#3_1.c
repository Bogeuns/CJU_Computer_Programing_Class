1#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define NUM_FLIPS 10000
#define INITIAL_STATUS 100
#define END_COND 999
#define HEADS 0
#define TAILS 1

// Define constants for forward and backward statuses, assuming they represent HEADS and TAILS
#define COIN_FWD_STATUS HEADS
#define COIN_BWD_STATUS TAILS

// Function to generate a random coin flip
unsigned int GenRandFlipCoin(unsigned int nRange)
{
    unsigned int nRes = 0;
    unsigned int nNum = 0;

    while (1)
    {
        nNum = rand();
        nRes = (unsigned int)(nNum) % nRange;

        // Check if the result matches one of the statuses (HEADS or TAILS)
        if (nRes == COIN_FWD_STATUS || nRes == COIN_BWD_STATUS)
        {
            printf("nRes: %d\n", nRes); // Debugging output
            break;
        }
    }
    return nRes;
}

// Main function
int main(void)
{
    int choice = 0;

    // Initialize random seed directly in main
    srand((unsigned int)time(NULL));

    // Infinite loop for the menu
    while (choice != 2)
    {
        printf("Choose an option:\n");
        printf("1: Start Coin Flip Simulation\n");
        printf("2: Exit\n");
        scanf("%d", &choice);

        if (choice == 1)
        {
            // Initialize counts for heads and tails
            int headsCount = 0;
            int tailsCount = 0;

            // Flip the coin NUM_FLIPS times
            for (int i = 0; i < NUM_FLIPS; i++)
            {
                int result = GenRandFlipCoin(2); // Use GenRandFlipCoin with a range of 2 (HEADS or TAILS)
                if (result == HEADS)
                {
                    headsCount++;
                }
                else if (result == TAILS)
                {
                    tailsCount++;
                }
            }

            // Calculate probabilities
            double headsProbability = (double)headsCount / NUM_FLIPS * 100;
            double tailsProbability = (double)tailsCount / NUM_FLIPS * 100;

            // Display results in English
            printf("Total Flips: %d\n", NUM_FLIPS);
            printf("Heads Count: %d, Probability: %.2f%%\n", headsCount, headsProbability);
            printf("Tails Count: %d, Probability: %.2f%%\n", tailsCount, tailsProbability);
        }
        else if (choice == 2)
        {
            // Exit the program
            printf("Exiting the program.\n");
        }
        else
        {
            // Handle invalid input
            printf("Invalid choice. Please select a valid option.\n");
        }
    }

    return 0;
}