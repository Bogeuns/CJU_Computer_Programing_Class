#include <stdio.h>
#include <stdlib.h>                                                 // Functions for random variables
#include <time.h>                                                   // Seeds for random variables

// Generates an array of random double values within a given range
int GenerateArray(double *array, int size, double min, double max);

// Reverses the order of elements in the array
int CalcInverseArray(double *array, int size);

// Prints the contents of the array
int PrintArray(const double *array, int size);

int main(void)
{
    const int size = 10;                                            // The array size
    double array[size];
    double *pArray = array;
    double min = -100.0, max = 100.0;

    srand((unsigned int)time(NULL));                                // Initializes random value generation

    GenerateArray(pArray, size, min, max);
    PrintArray(pArray, size);

    printf("\nReversed array:\n");
    CalcInverseArray(pArray, size);
    PrintArray(pArray, size);

    return 0;
}

int GenerateArray(double *array, int size, double min, double max)
{
    double *end = array + size;
    for (double *p = array; p < end; p++)
    {
        *p = min + (max - min) * ((double)rand() / RAND_MAX);       // Random value in range [min, max]
    }
    return 0;
}

int CalcInverseArray(double *array, int size)
{
    double *start = array;
    double *end = array + size - 1;

    while (start < end)
    {
        double temp = *start;
        *start = *end;
        *end = temp;

        start++;
        end--;
    }
    return 0;
}

int PrintArray(const double *array, int size)
{
    const double *end = array + size;
    for (const double *p = array; p < end; p++)
    {
        printf("%.2lf ", *p);
    }
    printf("\n");
    return 0;
}