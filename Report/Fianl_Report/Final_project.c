#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Constants
#define INPUT_SIZE 3
#define OUTPUT_SIZE 5
#define FILE_NAME "Mohr_Prb.txt" // Input file name
#define OUTPUT_FILE "Result_Mohr_circle.txt" // Output file name

// Function declarations
int readInputFromFile(const char *filename, double *input);
void calculateMohrsCircle(double *input, double *output);
void saveAndPrintResults(const char *filename, double *output);

int main() {
    // Input array (sigma_x, sigma_y, tau_xy)
    double input[INPUT_SIZE];

    // Read input from file
    if (!readInputFromFile(FILE_NAME, input)) {
        printf("\nError: Could not read input values from '%s'.\n", FILE_NAME);
        return 1;
    }

    // Print read values
    printf("\nRead Input Values:\n");
    printf("Sigma_x = %.2f\n", input[0]);
    printf("Sigma_y = %.2f\n", input[1]);
    printf("Tau_xy = %.2f\n", input[2]);

    // Output array for calculation results
    double output[OUTPUT_SIZE];

    // Perform calculations
    calculateMohrsCircle(input, output);

    // Save and print results
    saveAndPrintResults(OUTPUT_FILE, output);

    return 0;
}

// Function to read input values from a file
int readInputFromFile(const char *filename, double *input) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("\nError: Could not open file '%s'.\n", filename);
        return 0;
    }

    // Read values without units
    int result = fscanf(file, "Sigma_x: %lf\nSigma_y: %lf\nTau_xy: %lf", 
                        &input[0], &input[1], &input[2]);

    fclose(file);

    if (result != 3) {
        printf("\nError: File format is incorrect.\n");
        printf("Expected format:\nSigma_x: <value>\nSigma_y: <value>\nTau_xy: <value>\n");
        return 0;
    }

    return 1;
}

// Function to calculate Mohr's Circle values
void calculateMohrsCircle(double *input, double *output) {
    double sigma_x = input[0];
    double sigma_y = input[1];
    double tau_xy = input[2];

    // Calculate average normal stress
    output[0] = (sigma_x + sigma_y) / 2;

    // Calculate radius
    output[1] = sqrt(pow((sigma_x - sigma_y) / 2, 2) + pow(tau_xy, 2));

    // Calculate principal stresses
    output[2] = output[0] + output[1];
    output[3] = output[0] - output[1];

    // Calculate maximum shear stress
    output[4] = output[1];
}

// Function to save and print results
void saveAndPrintResults(const char *filename, double *output) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        printf("\nError: Could not create or write to the file '%s'.\n", filename);
        return;
    }

    // Titles
    fprintf(file, "Mohr's Circle Results\n");
    fprintf(file, "======================\n");
    printf("\nMohr's Circle Results:\n");
    printf("=======================\n");

    // Labels for results
    const char *labels[] = {"Sigma_avg", "R (Radius)", "Sigma_1", "Sigma_2", "Tau_max"};

    // Save and print results
    for (int i = 0; i < OUTPUT_SIZE; i++) {
        fprintf(file, "%s = %.2f\n", labels[i], output[i]);
        printf("%s = %.2f\n", labels[i], output[i]);
    }

    fclose(file);
    printf("\nResults have been successfully saved to '%s'.\n", filename);
}