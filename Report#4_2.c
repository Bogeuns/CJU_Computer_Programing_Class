#include <stdio.h>
#include <stdlib.h>                                                 // Functions for random variables
#include <time.h>                                                   // Seeds for random variables
#include <math.h>                                                   // For square root calculation

#define MIN 0                                                       // Minimum range for random numbers
#define MAX 100                                                     // Maximum range for random numbers
#define ARRAY_CAPACITY 200                                          // Total array capacity (for memory, just in case)
#define ARRAY_SIZE 100                                              // Actual number of generated integers
#define SAMPLE_SIZE 10                                              // Number of selected integers

void GenRandSeed();                                                 // Initializes the random seed
unsigned int GenRandInt(unsigned int nMin, unsigned int nMax);      // Generates a random integer within a given range
int sum(int* p_arr, int arr_size);                                  // Calculates the sum of array elements
void dev(int* p_arr, int avg, int arr_size, int* p_arr_dev);        // Computes deviations from the average
int var(int avg, int arr_size, int* p_arr_dev);                     // Calculates the variance
int std_dev(int var);                                               // Calculates the standard deviation

int main(void)
{
    int arr[ARRAY_CAPACITY] = { 0 };                                // Array with capacity for 200 elements (for memory, just in case)
    int arr_dev[SAMPLE_SIZE] = { 0 };                               // Array to hold deviations for the sample
    int* p_arr = arr;
    int* p_arr_dev = arr_dev;
    int sum_res, avg, var_res, std_dev_res = 0;
    int start_index = 0;

    GenRandSeed();                                                  // Initializes the random seed

    // Fill the first 100 elements of the array with random numbers
    for (int i = 0; i < ARRAY_SIZE; i++)
    {
        arr[i] = GenRandInt(MIN, MAX);
    }

    // User specifies the starting index for the range
    printf("Enter the starting index (0 to %d) for selecting %d integers: ", ARRAY_SIZE - SAMPLE_SIZE, SAMPLE_SIZE);
    scanf("%d", &start_index);

    // Validate the range
    if (start_index < 0 || start_index > ARRAY_SIZE - SAMPLE_SIZE)
    {
        printf("Invalid index. Please restart the program and try again.\n");
        return -1;
    }

    // Calculate statistics for the selected range
    sum_res = sum(p_arr + start_index, SAMPLE_SIZE);                // Calculate sum
    avg = sum_res / SAMPLE_SIZE;                                    // Calculate average
    dev(p_arr + start_index, avg, SAMPLE_SIZE, p_arr_dev);          // Calculate deviations
    var_res = var(avg, SAMPLE_SIZE, p_arr_dev);                     // Calculate variance
    std_dev_res = std_dev(var_res);                                 // Calculate standard deviation

    // Print the selected range
    printf("\nSelected range of %d integers: ", SAMPLE_SIZE);
    for (int i = start_index; i < start_index + SAMPLE_SIZE; i++)
    {
        printf("%3d ", arr[i]);
    }
    printf("\n");

    // Print the results
    printf("Sum: %d, Variance: %d, Standard Deviation: %d\n", sum_res, var_res, std_dev_res);

    return 0;
}

void GenRandSeed()
{
    srand((unsigned int)(time(NULL)));                              // Seed initialization with the current time
    return;
}

unsigned int GenRandInt(unsigned int nMin, unsigned int nMax)
{
    return nMin + rand() % (nMax - nMin + 1);                       // Generate a random integer in the range [nMin, nMax]
}

int sum(int* p_arr, int arr_size)
{
    int res = 0;
    for (int i = 0; i < arr_size; i++)
    {
        res += *(p_arr + i);                                        // Accumulate array elements
    }
    return res;
}

void dev(int* p_arr, int avg, int arr_size, int* p_arr_dev)
{
    for (int i = 0; i < arr_size; i++)
    {
        *(p_arr_dev + i) = *(p_arr + i) - avg;                      // Calculate deviation from the average
    }
}

int var(int avg, int arr_size, int* p_arr_dev)
{
    int res = 0;
    for (int i = 0; i < arr_size; i++)
    {
        res += (*(p_arr_dev + i)) * (*(p_arr_dev + i));             // Sum of squared deviations
    }
    return res / arr_size;                                          // Return variance
}

int std_dev(int var)
{
    return sqrt(var);                                               // Compute square root for standard deviation
}