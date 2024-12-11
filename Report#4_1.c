#include <stdio.h>

// Computes the cross product of two 3D vectors
void cross_product(int* arr_1, int* arr_2, int* arr_cross_res);

// Computes the dot product of two 3D vectors
int dot_product(int* arr_1, int* arr_2);

int main(void)
{
    const int size = 3;                                            // The size of the vectors (3D vectors)
    int arr_1[size];                                               // First 3D vector
    int arr_2[size];                                               // Second 3D vector
    int arr_cross_res[size] = { 0 };                               // Resultant vector for cross product
    int dot_res = 0;                                               // Result for dot product

    // Input for first vector
    printf("Enter 3 components of the first vector (separated by spaces): ");
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &arr_1[i]);
    }

    // Input for second vector
    printf("Enter 3 components of the second vector (separated by spaces): ");
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &arr_2[i]);
    }

    // Displaying input vectors
    printf("\nVector 1: (%d, %d, %d)\n", arr_1[0], arr_1[1], arr_1[2]);
    printf("Vector 2: (%d, %d, %d)\n", arr_2[0], arr_2[1], arr_2[2]);

    cross_product(arr_1, arr_2, arr_cross_res);                    // Computes the cross product
    dot_res = dot_product(arr_1, arr_2);                           // Computes the dot product

    // Displaying results
    printf("\nCross product: (%d, %d, %d)\n", arr_cross_res[0], arr_cross_res[1], arr_cross_res[2]);
    printf("Dot product: %d\n", dot_res);

    return 0;
}

void cross_product(int* arr_1, int* arr_2, int* arr_cross_res)
{
    // Computes each component of the cross product using the determinant formula
    arr_cross_res[0] = arr_1[1] * arr_2[2] - arr_1[2] * arr_2[1];
    arr_cross_res[1] = arr_1[2] * arr_2[0] - arr_1[0] * arr_2[2];
    arr_cross_res[2] = arr_1[0] * arr_2[1] - arr_1[1] * arr_2[0];
}

int dot_product(int* arr_1, int* arr_2)
{
    // Computes the sum of the products of corresponding components
    return arr_1[0] * arr_2[0] + arr_1[1] * arr_2[1] + arr_1[2] * arr_2[2];
}