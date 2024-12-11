#include <stdio.h>

int main() 
{
    float score;
    int grade;

    printf("점수를 입력하세요 (0.0 ~ 100.0): ");
    scanf("%f", &score);

    if (score < 0.0 || score > 100.0) 
    {
        printf("잘못된 점수입니다. 0.0에서 100.0 사이의 점수를 입력하세요.\n");
    } 
    else 
    {
        grade = (int)score / 10; // 점수를 10으로 나눈 정수값을 사용

        switch (grade) 
        {
            case 10: // 100점인 경우
            case 9:
                printf("학점: A\n");
                break;
            case 8:
                printf("학점: B\n");
                break;
            case 7:
                printf("학점: C\n");
                break;
            case 6:
                printf("학점: D\n");
                break;
            default:
                printf("학점: F\n");
                break;
        }
    }

    return 0;
}
