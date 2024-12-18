#include <stdio.h>

int main(void) 
{
    int num1, num2, a, b, gcd, lcm;

    // Get two numbers from the user
    printf("최대공약수와 최소공배수를 알고싶은 두 가지 수를 입력해 주세요: ");
    scanf("%d %d", &num1, &num2);
 
    // The temp numbers for calculate (Since we have two numbers with two calculations, we need four characters.)
    a = num1;
    b = num2;

    // Calculate GCD using Euclidean algorithm
    while (b != 0) 
    {
        int temp = b;
        b = a % b;
        a = temp;
    }
    gcd = a;  
    // Now, 'a' contains the GCD

    // Calculate LCM using the formula: LCM = (num1 * num2) / GCD
    lcm = (num1 * num2) / gcd;

    // Output the results
    printf("최대공약수: %d\n", gcd);
    printf("최소공배수: %d\n", lcm);

    return 0;
}
