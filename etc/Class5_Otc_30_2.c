#include <stdio.h>
#include <math.h>

// Function to convert degrees to radians
double degreesToRadians(double degrees) {
    return degrees * (M_PI / 180.0);  // Convert degrees to radians
}

int main() {
    char type;
    double angle, result;

    // Step 1: Ask for Sin or Cos
    printf("Type the Sin or Cos that you want to calculate (S for Sin, C for Cos): ");
    scanf(" %c", &type);

    // Validate input for Sin or Cos
    if (type != 'S' && type != 's' && type != 'C' && type != 'c') {
        printf("Invalid input. Please type 'S' for Sin or 'C' for Cos.\n");
        return 1;
    }

    // Step 2: Ask for angle in degrees
    printf("Type the angle in 'Degree' (Note: Not rad) from 0 to 180: ");
    scanf("%lf", &angle);

    // Validate angle input
    if (angle < 0 || angle > 180) {
        printf("Invalid angle. Please provide an angle between 0 and 180 degrees.\n");
        return 1;
    }

    // Step 3: Calculate Sin or Cos based on input
    if (type == 'S' || type == 's') {
        result = sin(degreesToRadians(angle));
        printf("The Sin(%.0f) is %.4f\n", angle, result);
    } else if (type == 'C' || type == 'c') {
        result = cos(degreesToRadians(angle));
        printf("The Cos(%.0f) is %.4f\n", angle, result);
    }

    return 0;
}