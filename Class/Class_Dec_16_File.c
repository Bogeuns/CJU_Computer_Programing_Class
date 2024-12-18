#include <stdio.h>

int main(void)
{
    FILE* fp;

    fp = fopen("/Users/jiwon/Documents/CJU_Computer_Programing_Class/test_read.txt", "r");
    if(fp == NULL)
    {
        printf("Cannot open file... Please check the file path... \n");
        return 1;
    }

    printf("Success; file open\n");

    fclose(fp);
    return 0;
}