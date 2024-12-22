#include <stdio.h>
#include <math.h>

// 상수 정의
#define INPUT_SIZE 3
#define OUTPUT_SIZE 5

// 함수 선언
void calculateMohrCircle(double *input, double *output);
void saveToFile(const char *filename, double *input, double *output);

int main() {
    // 입력값 배열 (sigma_x, sigma_y, tau_xy)
    double input[INPUT_SIZE];
    printf("Enter sigma_x, sigma_y, tau_xy: ");
    scanf("%lf %lf %lf", &input[0], &input[1], &input[2]);

    // 출력값 배열 (sigma_avg, R, sigma_1, sigma_2, tau_max)
    double output[OUTPUT_SIZE];

    // 모어 원 계산
    calculateMohrCircle(input, output);

    // 결과 출력
    printf("\nMohr Circle Results:\n");
    printf("=====================\n");
    printf("Sigma_avg: %.2f MPa\n", output[0]);
    printf("R (Radius): %.2f MPa\n", output[1]);
    printf("Sigma_1: %.2f MPa\n", output[2]);
    printf("Sigma_2: %.2f MPa\n", output[3]);
    printf("Tau_max: %.2f MPa\n", output[4]);

    // 결과를 파일에 저장
    saveToFile("mohr_circle_results.txt", input, output);

    return 0;
}

// 모어 원 계산 함수
void calculateMohrCircle(double *input, double *output) {
    double sigma_x = input[0];
    double sigma_y = input[1];
    double tau_xy = input[2];

    // 평균 정상 응력
    output[0] = (sigma_x + sigma_y) / 2;

    // 반경 계산
    output[1] = sqrt(pow((sigma_x - sigma_y) / 2, 2) + pow(tau_xy, 2));

    // 주응력
    output[2] = output[0] + output[1];
    output[3] = output[0] - output[1];

    // 최대 전단응력
    output[4] = output[1];
}

// 결과를 파일에 저장하는 함수
void saveToFile(const char *filename, double *input, double *output) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error: Could not open file for writing.\n");
        return;
    }

    fprintf(file, "Mohr Circle Data\n");
    fprintf(file, "=================\n");
    fprintf(file, "Input Data:\n");
    fprintf(file, "Sigma_x: %.2f MPa\n", input[0]);
    fprintf(file, "Sigma_y: %.2f MPa\n", input[1]);
    fprintf(file, "Tau_xy: %.2f MPa\n\n", input[2]);

    fprintf(file, "Results:\n");
    fprintf(file, "Sigma_avg: %.2f MPa\n", output[0]);
    fprintf(file, "R (Radius): %.2f MPa\n", output[1]);
    fprintf(file, "Sigma_1: %.2f MPa\n", output[2]);
    fprintf(file, "Sigma_2: %.2f MPa\n", output[3]);
    fprintf(file, "Tau_max: %.2f MPa\n", output[4]);

    fclose(file);
    printf("\nResults have been saved to '%s'\n", filename);
}