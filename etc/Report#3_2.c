#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define NUM_COUNT 10
#define RANGE_MIN 1
#define RANGE_MAX 100

// Function to generate a random number in a given range
int GenRandNum(int min, int max)
{
    return rand() % (max - min + 1) + min;
}

int main(void)
{
    // Initialize random seed
    srand((unsigned int)time(NULL));

    // Initialize variables
    int numbers[NUM_COUNT];
    int sum = 0;
    double mean = 0.0;
    double variance = 0.0;
    double stddev = 0.0;

    // Generate random numbers and calculate sum
    printf("Generated Numbers: ");
    for (int i = 0; i < NUM_COUNT; i++)
    {
        numbers[i] = GenRandNum(RANGE_MIN, RANGE_MAX);
        sum += numbers[i];
        printf("%d ", numbers[i]);
    }
    printf("\n");

    // Calculate mean
    mean = (double)sum / NUM_COUNT;

    // Calculate variance
    for (int i = 0; i < NUM_COUNT; i++)
    {
        variance += pow(numbers[i] - mean, 2);
    }
    variance /= NUM_COUNT;

    // Calculate standard deviation
    stddev = sqrt(variance);

    // Display results
    printf("Sum: %d\n", sum);
    printf("Mean: %.2f\n", mean);
    printf("Variance: %.2f\n", variance);
    printf("Standard Deviation: %.2f\n", stddev);

    return 0;
}