#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void generateArray(int *array, int size);
double calculateSum(const int *array, int size);
double calculateVariance(const int *array, int size, double mean);
double calculateStandardDeviation(double variance);

int main(void) {
    int size = 0, additionalSize = 0;
    printf("Enter the initial array size: ");
    scanf("%d", &size);

    int *array = (int *)malloc(size * sizeof(int));
    if (array == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    generateArray(array, size);
    printf("Generated array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    double sum = calculateSum(array, size);
    double mean = sum / size;
    double variance = calculateVariance(array, size, mean);
    double stdDev = calculateStandardDeviation(variance);

    printf("Sum: %.2lf, Mean: %.2lf, Variance: %.2lf, Standard Deviation: %.2lf\n", sum, mean, variance, stdDev);

    printf("Enter the size of additional numbers: ");
    scanf("%d", &additionalSize);
    array = (int *)realloc(array, (size + additionalSize) * sizeof(int));
    if (array == NULL) {
        printf("Memory reallocation failed!\n");
        return 1;
    }

    generateArray(array + size, additionalSize);
    printf("Additional array: ");
    for (int i = size; i < size + additionalSize; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    size += additionalSize;
    sum = calculateSum(array, size);
    mean = sum / size;
    variance = calculateVariance(array, size, mean);
    stdDev = calculateStandardDeviation(variance);

    printf("New Sum: %.2lf, New Mean: %.2lf, New Variance: %.2lf, New Standard Deviation: %.2lf\n", sum, mean, variance, stdDev);

    free(array);
    return 0;
}

void generateArray(int *array, int size) {
    for (int i = 0; i < size; i++) {
        array[i] = rand() % 101; // Random values between 0 and 100
    }
}

double calculateSum(const int *array, int size) {
    double sum = 0;
    for (int i = 0; i < size; i++) {
        sum += array[i];
    }
    return sum;
}

double calculateVariance(const int *array, int size, double mean) {
    double variance = 0;
    for (int i = 0; i < size; i++) {
        variance += pow(array[i] - mean, 2);
    }
    return variance / size;
}

double calculateStandardDeviation(double variance) {
    return sqrt(variance);
}