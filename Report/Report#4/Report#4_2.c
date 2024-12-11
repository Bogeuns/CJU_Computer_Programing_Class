#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define MIN 0
#define MAX 100
#define ARRAY_SIZE 200 // For memory, just in case

void GenRandSeed() {
    srand((unsigned int)(time(NULL)));
}

unsigned int GenRandInt(unsigned int nMin, unsigned int nMax) {
    return nMin + rand() % (nMax - nMin + 1);
}

double sum(const double* pArr, int arrSize) {
    double res = 0.0;
    for (int i = 0; i < arrSize; i++) {
        res += *(pArr + i);
    }
    return res;
}

void dev(const double* pArr, double avg, int arrSize, double* pArrDev) {
    for (int i = 0; i < arrSize; i++) {
        *(pArrDev + i) = *(pArr + i) - avg;
    }
}

double var(double avg, int arrSize, const double* pArrDev) {
    double res = 0.0;
    for (int i = 0; i < arrSize; i++) {
        res += (*(pArrDev + i)) * (*(pArrDev + i));
    }
    return res / arrSize;
}

double std_dev(double var) {
    return sqrt(var);
}

int main(void) {
    GenRandSeed();

    double arr[ARRAY_SIZE] = {0};
    double arrDev[ARRAY_SIZE] = {0};
    double* pArr = arr;
    double* pArrDev = arrDev;
    const int totalSize = ARRAY_SIZE;
    const int selectedSize = 100; // Only 100 elements will be used
    double sumRes, avg, varRes, stdDevRes;

    // Generate random values
    for (int i = 0; i < selectedSize; i++) {
        arr[i] = GenRandInt(MIN, MAX);
    }

    // Calculate statistics
    sumRes = sum(pArr, selectedSize);
    avg = sumRes / selectedSize;
    dev(pArr, avg, selectedSize, pArrDev);
    varRes = var(avg, selectedSize, pArrDev);
    stdDevRes = std_dev(varRes);

    // Print array
    printf("Random array (%d elements):\n", selectedSize);
    for (int i = 0; i < selectedSize; i++) {
        printf("%.2lf ", arr[i]);
    }
    printf("\n");

    // Print results
    printf("Sum: %.2lf, Variance: %.2lf, Std. Dev: %.2lf\n", sumRes, varRes, stdDevRes);

    return 0;
}