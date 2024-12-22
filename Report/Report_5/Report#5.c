#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STUDENTS 100
#define KOREAN 0
#define ENGLISH 1
#define MATH 2

typedef struct {
    char name[50];
    int id;
    int scores[3];
    double average;
    int class_rank;
    int overall_rank;
} Student;

void calculate_average(Student *students, int count) {
    for (int i = 0; i < count; i++) {
        students[i].average = (students[i].scores[KOREAN] +
                               students[i].scores[ENGLISH] +
                               students[i].scores[MATH]) / 3.0;
    }
}

void calculate_rank(Student *students, int count) {
    for (int i = 0; i < count; i++) {
        students[i].class_rank = 1;
        for (int j = 0; j < count; j++) {
            if (students[j].average > students[i].average) {
                students[i].class_rank++;
            }
        }
    }
}

void calculate_overall_rank(Student *students1, int count1, Student *students2, int count2) {
    Student *all_students[MAX_STUDENTS * 2];
    int total_count = count1 + count2;

    for (int i = 0; i < count1; i++) {
        all_students[i] = &students1[i];
    }
    for (int i = 0; i < count2; i++) {
        all_students[count1 + i] = &students2[i];
    }

    for (int i = 0; i < total_count; i++) {
        all_students[i]->overall_rank = 1;
        for (int j = 0; j < total_count; j++) {
            if (all_students[j]->average > all_students[i]->average) {
                all_students[i]->overall_rank++;
            }
        }
    }
}

void print_student_results(Student *students, int count, const char *filename) {
    FILE *file = fopen(filename, "w");
    if (!file) {
        perror("Error opening results file");
        exit(EXIT_FAILURE);
    }

    fprintf(file, "====================================================================================\n");
    fprintf(file, "| %-10s | %-15s | %-8s | %-8s | %-8s | %-10s | %-10s | %-12s |\n", 
            "ID", "Name", "Korean", "English", "Math", "Average", "Class Rank", "Overall Rank");
    fprintf(file, "====================================================================================\n");

    for (int i = 0; i < count; i++) {
        fprintf(file, "| %-10d | %-15s | %-8d | %-8d | %-8d | %-10.2lf | %-10d | %-12d |\n",
                students[i].id, students[i].name,
                students[i].scores[KOREAN], students[i].scores[ENGLISH],
                students[i].scores[MATH], students[i].average,
                students[i].class_rank, students[i].overall_rank);
    }
    fprintf(file, "====================================================================================\n");
    fclose(file);
}

void calculate_class_results(Student *students1, int count1, Student *students2, int count2, const char *filename) {
    FILE *file = fopen(filename, "w");
    if (!file) {
        perror("Error opening class results file");
        exit(EXIT_FAILURE);
    }

    double class1_average = 0.0, class2_average = 0.0;
    for (int i = 0; i < count1; i++) {
        class1_average += students1[i].average;
    }
    for (int i = 0; i < count2; i++) {
        class2_average += students2[i].average;
    }
    class1_average /= count1;
    class2_average /= count2;

    fprintf(file, "Class 1 Average: %.2lf\n", class1_average);
    fprintf(file, "Class 2 Average: %.2lf\n", class2_average);
    fclose(file);
}

int main(void) {
    Student students1[MAX_STUDENTS], students2[MAX_STUDENTS];
    int count1 = 0, count2 = 0;

    FILE *file1 = fopen("students_1.txt", "r");
    if (!file1) {
        perror("Error opening students_1.txt");
        return 1;
    }
    while (fscanf(file1, "%s %d %d %d %d", students1[count1].name, &students1[count1].id,
                  &students1[count1].scores[KOREAN], &students1[count1].scores[ENGLISH],
                  &students1[count1].scores[MATH]) == 5) {
        count1++;
    }
    fclose(file1);

    FILE *file2 = fopen("students_2.txt", "r");
    if (!file2) {
        perror("Error opening students_2.txt");
        return 1;
    }
    while (fscanf(file2, "%s %d %d %d %d", students2[count2].name, &students2[count2].id,
                  &students2[count2].scores[KOREAN], &students2[count2].scores[ENGLISH],
                  &students2[count2].scores[MATH]) == 5) {
        count2++;
    }
    fclose(file2);

    calculate_average(students1, count1);
    calculate_average(students2, count2);
    calculate_rank(students1, count1);
    calculate_rank(students2, count2);
    calculate_overall_rank(students1, count1, students2, count2);

    print_student_results(students1, count1, "students_1_results.txt");
    print_student_results(students2, count2, "students_2_results.txt");

    calculate_class_results(students1, count1, students2, count2, "class_results.txt");

    printf("Results saved to files.\n");

    return 0;
}