#include <stdio.h>

int main() 
{
    int number;
    
    printf("정수를 입력하세요: ");
    scanf("%d", &number);
    
    switch (number % 2) 
    {
        case 0:
            printf("%d는 짝수입니다.\n", number);
            break;
        
        case 1:
        case -1: // 음수를 처리하기 위한 경우 추가
            printf("%d는 홀수입니다.\n", number);
            break;
    }
    
    return 0;
}
