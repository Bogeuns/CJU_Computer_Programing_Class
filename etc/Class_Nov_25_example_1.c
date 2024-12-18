#include <stdio.h>

int main(void)
{
    int A[3] = {1, 2, 3}; // Numbers for print (Array [A])
    int B[10]; // Variable number (Array [B])
    int i; // Variable for count up with [B]

    // Set the variables to reach [B] with printing [A]
    for (i = 0; i < 10; i++)
    {
        B[i] = A[i % 3];
    }
    // Print [A], counting up with variables [i] until reach [B]
    for (i = 0; i < 10; i++)
    {
        printf("%d ", B[i]);
    }

    // Skip a space for next term
    printf("\n");
    return 0;
}