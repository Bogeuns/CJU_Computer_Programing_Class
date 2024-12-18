#include <stdio.h>
#include <stdlib.h>

#pragma pack(push, 1) // Remove padding between structure members
typedef struct
{
    char chC1;         // Single character
    int nNum1;         // First integer
    int nNum2;         // Second integer
    char strS1[40];    // String with a maximum size of 40 bytes
} Data;
#pragma pack(pop)

int main(void)
{
    FILE *txtFile, *binFile; // File pointers for input and output files
    Data d1;                 // Structure to hold the data

    // Open the text file for reading
    if (fopen_s(&txtFile, "data2.txt", "r") != 0)
    {
        printf("Error: Cannot open 'data2.txt' for reading.\n");
        return 1;
    }

    // Open the binary file for writing
    if (fopen_s(&binFile, "data2.bin", "wb") != 0)
    {
        printf("Error: Cannot open 'data2.bin' for writing.\n");
        fclose(txtFile);
        return 1;
    }

    printf("Reading from 'data2.txt' and writing to 'data2.bin'...\n");

    // Read data line by line from the text file and write to binary file
    while (fscanf_s(txtFile, " %c %d %d %39s", 
                    &d1.chC1,
                    (unsigned int)sizeof(d1.chC1), 
                    &d1.nNum1, 
                    &d1.nNum2, 
                    d1.strS1, 
                    (unsigned int)sizeof(d1.strS1)) == 4)
    {
        // Write the structure data to the binary file
        fwrite(&d1, sizeof(Data), 1, binFile);
    }

    printf("Conversion completed successfully!\n");

    // Close both files
    fclose(txtFile);
    fclose(binFile);

    return 0;
}