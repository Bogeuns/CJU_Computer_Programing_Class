#include <stdio.h>
#include <stdlib.h>                                                 // Functions for random variables
#include <time.h>                                                   // Seeds for random variables

// Generates an array of random integer values within a given range
int GenerateArray(int *array, int size, int min, int max);

// Separates even and odd numbers into two different arrays
int CalcEvenOddArray(const int *array, int size, int *evenArray, int *oddArray, int *evenCount, int *oddCount);

// Prints the contents of an array
int PrintArray(const int *array, int size, const char *message);

int main(void)
{
    const int size = 10;                                            // The array size
    int array[size];
    int evenArray[size];                                            // Array to store even numbers
    int oddArray[size];                                             // Array to store odd numbers
    int evenCount = 0, oddCount = 0;                                // Counters for even and odd numbers
    int *pArray = array;

    srand((unsigned int)time(NULL));                                // Initializes random value generation

    GenerateArray(pArray, size, 0, 100);                            // Generates the random array
    PrintArray(pArray, size, "Generated array:");                   // Prints the array in its initial state

    CalcEvenOddArray(pArray, size, evenArray, oddArray, &evenCount, &oddCount); // Separates even and odd numbers

    PrintArray(evenArray, evenCount, "Even numbers:");              // Prints the even numbers
    PrintArray(oddArray, oddCount, "Odd numbers:");                 // Prints the odd numbers

    return 0;
}

int GenerateArray(int *array, int size, int min, int max)
{
    int *end = array + size;
    for (int *p = array; p < end; p++)
    {
        *p = min + rand() % (max - min + 1);                        // Random integer in range [min, max]
    }
    return 0;
}

int CalcEvenOddArray(const int *array, int size, int *evenArray, int *oddArray, int *evenCount, int *oddCount)
{
    const int *end = array + size;

    for (const int *p = array; p < end; p++)                        // Iterates through the input array
    {
        if (*p % 2 == 0)                                            // Checks if the number is even
        {
            evenArray[*evenCount] = *p;
            (*evenCount)++;
        }
        else                                                       // Otherwise, it's odd
        {
            oddArray[*oddCount] = *p;
            (*oddCount)++;
        }
    }
    return 0;
}

int PrintArray(const int *array, int size, const char *message)
{
    printf("%s\n", message);                                       // Prints the provided message
    const int *end = array + size;

    for (const int *p = array; p < end; p++)                       // Iterates through the array
    {
        printf("%d ", *p);                                         // Prints each element
    }
    printf("\n");
    return 0;
}