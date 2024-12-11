#include <stdio.h>

// Function to input array elements
void SetArray(double *pDArr, int nArrSize)
{
    printf("Input size(%d) array:\n", nArrSize);

    for (unsigned int i = 0; i < nArrSize; i++)
    {
        printf("Enter element [%d]: ", i);
        scanf("%lf", pDArr + i);
    }
}

// Function to print array elements and debugging information
void PrintArray(double *pDArr, int nArrSize)
{
    printf("\nArray elements and debugging info:\n");

    for (unsigned int i = 0; i < nArrSize; i++)
    {
        // Printing array element using multiple formats
        printf("[%d](%u, %.4lf)\n", i, &pDArr[i], pDArr[i]);
        printf("[%d](%u, %.4lf)\n", i, pDArr + i, *(pDArr + i));
        printf("[%d](%u, %.4lf)\n", i, &pDArr[i], *(pDArr + i));
        printf("[%d](%u, %.4lf)\n", i, pDArr + i, *(pDArr + i));
    }
}

int main(void)
{
    double dArr[5] = {};
    double *pDArr = dArr;
    const int nArrSize = sizeof(dArr) / sizeof(dArr[0]);

    SetArray(pDArr, nArrSize);
    PrintArray(pDArr, nArrSize);

    return 0;
}