#include <stdio.h>
#include <stdlib.h>                                                 //Function for random variables
#include <time.h>                                                   //Seeds for random variables

int GenerateArray(double *array, int size, double min, double max); // Generate the random value with given range (size and double array)
int CalcSortArray(double *array, int size, int order);              // Sorts by comparing the numbers as ascending or descending orders
int PrintArray(const double *array, int size);                      // Ready for print the values

int main(void)
{
    const int size = 10;                                            // The Array size (Given from the question)
    double array[size];
    double *pArray = array;
    double min = -100.0, max = 100.0;

    srand((unsigned int)time(NULL));                                // Makes random value

    GenerateArray(pArray, size, min, max);
    PrintArray(pArray, size);

    printf("\nSorted array in ascending order:\n");                 //Ascending order printing
    CalcSortArray(pArray, size, 0);
    PrintArray(pArray, size);

    printf("\nSorted array in descending order:\n");                //Desending order prining
    CalcSortArray(pArray, size, 1);
    PrintArray(pArray, size);

    return 0;
}

int GenerateArray(double *array, int size, double min, double max)  //Pointer for the Array [Gen rad num]
{
    double *end = array + size;
    for (double *p = array; p < end; p++)
    {
        *p = min + (max - min) * ((double)rand() / RAND_MAX);
    }
    return 0;
}

int CalcSortArray(double *array, int size, int order)               //Pointer for the Array [ order 0 for the ascending, order 1 for descending ]
{
    double *end = array + size;
    for (double *p = array; p < end - 1; p++)
    {
        for (double *q = array; q < end - (p - array) - 1; q++)
        {
            if ((order == 0 && *q > *(q + 1)) || (order == 1 && *q < *(q + 1)))
            {
                double temp = *q;
                *q = *(q + 1);
                *(q + 1) = temp;
            }
        }
    }
    return 0;
}

int PrintArray(const double *array, int size)                       // Pointer for the Array [ outer loop for fixed elements, inner loop for adjacent comparisons ]
{
    const double *end = array + size;
    for (const double *p = array; p < end; p++)
    {
        printf("%.2lf ", *p);
    }
    printf("\n");
    return 0;
}