#include <stdio.h>

// without padding byte in the structure
#pragma pack(push, 1)
typedef struct
{
	char chC1;
	int nNum1;
	int nNum2;
	char strS1[40];
} Data;
#pragma pack(pop)

int main(void)
{
	Data d1;
	FILE* fp;

	// using birary file (fast)
	//fopen_s(&fp, "data2.bin", "rb");

	// using txt file (slow)
	fopen_s(&fp, "data2.txt", "r");

	// for debugging
	if (fp == NULL) 
	{
		printf("Cannot open file..Please check your file status\n");
		return 1;
	}

	// for debugging
	printf("struct size:%d\n", (unsigned int)(sizeof(Data)));

	// using binary file (fast)
	//fread(&d1, sizeof(Data), 1, fp);

	// using txt file (slow)
	fscanf_s(fp, "%c %d %d %39s", &d1.chC1, (unsigned int)(sizeof(d1.chC1)), &d1.nNum1, &d1.nNum2, d1.strS1, (unsigned int)(sizeof(d1.strS1)));

	// adding NULL character
	d1.strS1[sizeof(d1.strS1) - 1] = '\0';

	// for debugging
	printf("%c   %d   %d   %s\n", d1.chC1, d1.nNum1, d1.nNum2, d1.strS1);
	fclose(fp);
	return 0;
}