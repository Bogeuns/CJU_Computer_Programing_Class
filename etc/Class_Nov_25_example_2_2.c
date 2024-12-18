#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main(void)
{
    char input[100]; //Array for input str
    char output[100]; //Array for output str
    char temp[100]; // Array for temp (for change the letter)
    int count = 0; //Count strat with 0
    int i; //Variable for the counting up

    //Print for take the input vaule (or charcter)
    printf("문장 입력: ");
    fgets(input, sizeof(input), stdin);

    size_t len = strlen(input);
    if (len > 0 && input[len - 1] == '\n')
    {
        input[len - 1] = '\0';
    }

    strcpy(temp, input);

    for (i = 0; temp[i] != '\0'; i++)
    {
        if (isupper(temp[i]))
        {
            temp[i] = tolower(temp[i]);
            count++;
        }
    }

    strcpy(output, temp);

    printf("바뀐 문장: %s\n", output);
    printf("바꾼 문자 수: %d\n", count);

    return 0;
}