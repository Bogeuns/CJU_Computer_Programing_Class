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

    if (operator == '+')
    {
        printf("%d %c %d = %d\n", num1, operator, num2, num1 + num2);
    }
    else if (operator == '-')
    {
        printf("%d %c %d = %d\n", num1, operator, num2, num1 - num2);
    }
    else if (operator == '*')
    {
        printf("%d %c %d = %d\n", num1, operator, num2, num1 * num2);
    }
    else if (operator == '/')
    {
        if (num2 == 0) 
        {
            printf("0으로 나눌 수 없습니다.\n");
        }
        else
        {
            printf("%d %c %d = %d\n", num1, operator, num2, num1 / num2);
        }
    }
    else
    {
        printf("잘못된 수식 또는 연산자 입니다.\n");
    }

    return 0;
}
