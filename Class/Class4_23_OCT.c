#include <stdio.h>

int main(void)
{
    int mul, i;

    // Get the numbers for multiplication.
    printf("계산하고 싶은 구구단을 입력해 주세요 (2~9단): "); 
    if (scanf("%d", &mul)) {

        // Check if the input is within the valid range (2~9)
        if (mul >= 2 && mul <= 9) {
            // Print the multiplication table using a for loop
            for(i = 1; i <= 9; i++) {
                printf("%d x %d = %d\n", mul, i, mul * i);
            }
        } else {
            printf("잘못된 입력입니다. 2~9 사이의 숫자를 입력해 주세요.\n");
        }
    }

    return 0;
}
