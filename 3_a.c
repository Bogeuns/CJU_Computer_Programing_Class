#include <stdio.h>

int main() 
{
    float score;

    printf("점수를 입력하세요 (0.0 ~ 100.0): ");
    scanf("%f", &score);

    if (score < 0.0 || score > 100.0) 
    {
        printf("잘못된 점수입니다. 0.0에서 100.0 사이의 점수를 입력하세요.\n");
    } 
    else if (score >= 90.0) 
    {
        printf("학점: A\n");
    } 
    else if (score >= 80.0) 
    {
        printf("학점: B\n");
    } 
    else if (score >= 70.0) 
    {
        printf("학점: C\n");
    } 
    else if (score >= 60.0) 
    {
        printf("학점: D\n");
    } 
    else 
    {
        printf("학점: F\n");
    }

    return 0;
}
