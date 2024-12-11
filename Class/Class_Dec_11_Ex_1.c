#include <stdio.h>
#include <string.h>
#include <ctype.h>

void reverseWord(char *start, char *end) {
    while (start < end) {
        char temp = *start;
        *start = *end;
        *end = temp;
        start++;
        end--;
    }
}

int main() {
    char input[100];
    printf("Enter a string: ");
    fgets(input, sizeof(input), stdin);

    // Remove the newline character if it exists
    size_t len = strlen(input);
    if (len > 0 && input[len - 1] == '\n') {
        input[len - 1] = '\0';
    }

    char *wordStart = input;
    char *temp = input;

    while (*temp) {
        if (isspace(*temp) || *(temp + 1) == '\0') {
            if (*(temp + 1) == '\0') {
                temp++;  // Include the last character
            }
            reverseWord(wordStart, temp - 1); // Reverse the current word
            wordStart = temp + 1; // Move to the next word
        }
        temp++;
    }

    printf("Reversed words: %s\n", input);
    return 0;
}