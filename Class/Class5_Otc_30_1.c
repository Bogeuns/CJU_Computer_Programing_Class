#include <stdio.h>

// Step 1 :Convert Celsius to Fahrenheit
double celsiusToFahrenheit(double celsius) {
    return (celsius * 9.0 / 5.0) + 32;
}

// Step 2:Convert Fahrenheit to Celsius
double fahrenheitToCelsius(double fahrenheit) {
    return (fahrenheit - 32) * 5.0 / 9.0;
}

int main() {
    char type;
    double temperature;

    while (1) {
        printf("What do you want to convert from? (Type C for Celsius or F for Fahrenheit): ");
        scanf(" %c", &type);

        if (type == 'F' || type == 'f') {
            printf("Enter temperature in Fahrenheit: ");
            if (scanf("%lf", &temperature) != 1) {
                printf("Invalid temperature input. Please enter a numeric value.\n");
                return 1;
            }
            printf("%.2f°F is %.2f°C\n", temperature, fahrenheitToCelsius(temperature));
            break;
        } else if (type == 'C' || type == 'c') {
            printf("Enter temperature in Celsius: ");
            if (scanf("%lf", &temperature) != 1) {
                printf("Invalid temperature input. Please enter a numeric value.\n");
                return 1;
            }
            printf("%.2f°C is %.2f°F\n", temperature, celsiusToFahrenheit(temperature));
            break;
        } else {
            printf("You gave the wrong one. Please provide C or F only.\n");
            while (getchar() != '\n'); // Clear input buffer
        }
    }

    return 0;
}