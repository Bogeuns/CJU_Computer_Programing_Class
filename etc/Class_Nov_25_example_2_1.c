#include <stdio.h>
#include <string.h>

int main(void)
{
    char str1[80], str2[80]; //Array str1 , str2 to string.
    char temp[80]; //temp arry for memory (string swap)

    //Print very first scrren for input the vaule (or the charcter)
    printf("두 문자열 입력: ");
    scanf("%s %s", str1, str2);

    //Print the result [befroe]
    printf("바꾸기 전 : %s, %s\n", str1, str2);

    strcpy(temp, str1); //Copy text to temp
    strcpy(str1, str2); //Copy text from str2 to str1
    strcpy(str2, temp); //Copy text from temp to str2
    //Print the result  [after]
    printf("바꾼 후 : %s, %s\n", str1, str2); //Now, print all of result.

    return 0;
}