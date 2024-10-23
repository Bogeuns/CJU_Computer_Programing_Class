#include <stdio.h>

int main() 
{
    int num1, num2;
    
    printf("두 개의 정수를 입력하세요 (예: 6 3): ");
    scanf("%d %d", &num1, &num2);
    
    if (num2 == 0) 
    {
        printf("0으로 나눌 수 없습니다.\n");
    } 
    else 
    {
        switch (num1 % num2) 
        {
            case 0:
                printf("%d는 %d의 배수입니다.\n", num1, num2);
                break;
                
            default:
                printf("%d는 %d의 배수가 아닙니다.\n", num1, num2);
                break;
        }
    }
    
    return 0;
}
