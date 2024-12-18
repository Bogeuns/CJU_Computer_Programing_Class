#include <stdio.h>

int main() 
{
    int number;
    
    printf("정수를 입력하세요: ");
    scanf("%d", &number);
    
    if (number % 2 == 0) 
    {
        printf("%d는 짝수입니다.\n", number);
    } 
    else 
    {
        printf("%d는 홀수입니다.\n", number);
    }
    
    return 0;
}
