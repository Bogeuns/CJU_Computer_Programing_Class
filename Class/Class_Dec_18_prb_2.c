#include <stdio.h>
#include <stdlib.h>

#pragma pack(push, 1) // Remove padding between structure members
typedef struct {
    char chC1;       // Single character
    int nNum1;       // First integer
    int nNum2;       // Second integer
    char strS1[40];  // String with a maximum size of 40 bytes
} Data;
#pragma pack(pop)

int main(void) {
    FILE *txtFile, *binFile; // File pointers for text and binary files
    Data d1;                 // Structure to hold the data
    const char txtFilePath[] = "/Users/jiwon/Documents/CJU_Computer_Programing_Class/data2.txt";
    const char binFilePath[] = "/Users/jiwon/Documents/CJU_Computer_Programing_Class/data2.bin";

    // Open the text file for reading
    txtFile = fopen(txtFilePath, "r");
    if (txtFile == NULL) {
        perror("Error opening text file for reading");
        return EXIT_FAILURE;
    }

    // Open the binary file for writing
    binFile = fopen(binFilePath, "wb");
    if (binFile == NULL) {
        perror("Error opening binary file for writing");
        fclose(txtFile);
        return EXIT_FAILURE;
    }

    printf("Reading from '%s' and writing to '%s'...\n", txtFilePath, binFilePath);

    // Read data line by line from the text file and write to binary file
    while (fscanf(txtFile, " %c %d %d %39s",
                  &d1.chC1,
                  &d1.nNum1,
                  &d1.nNum2,
                  d1.strS1) == 4) {
        // Write the structure data to the binary file
        if (fwrite(&d1, sizeof(Data), 1, binFile) != 1) {
            perror("Error writing to binary file");
            fclose(txtFile);
            fclose(binFile);
            return EXIT_FAILURE;
        }
    }

    printf("Conversion completed successfully!\n");

    // Close both files
    fclose(txtFile);
    fclose(binFile);

    return EXIT_SUCCESS;
}