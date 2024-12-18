#include <stdio.h>

int main(void)
{
    int num1, num2;
    char operator;

    printf("계산하고 싶은 사칙 연산을 입력해 주세요: ");
    if (scanf("%d %c %d", &num1, &operator, &num2) != 3)
    {
        printf("잘못된 값입니다.\n");
        return 1;
    }

    switch (operator)
    {
        case '+':
            printf("%d %c %d = %d\n", num1, operator, num2, num1 + num2);
            break;

        case '-':
            printf("%d %c %d = %d\n", num1, operator, num2, num1 - num2);
            break;

        case '*':
            printf("%d %c %d = %d\n", num1, operator, num2, num1 * num2);
            break;

        case '/':
            if (num2 == 0) 
            {
                printf("0으로 나눌 수 없습니다.\n");
            }
            else
            {
                printf("%d %c %d = %d\n", num1, operator, num2, num1 / num2);
            }
            break;

        default:
            printf("지원하지 않는 연산자입니다.\n");
            break;
    }

    return 0;
}