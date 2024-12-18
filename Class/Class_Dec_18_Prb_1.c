#include <stdio.h>
#include <math.h>

// Define a structure to represent a 3D point
typedef struct {
    double x; // X-coordinate
    double y; // Y-coordinate
    double z; // Z-coordinate
} Point3D;

// Function prototypes
void inputPoints(Point3D* p1, Point3D* p2);
double calculateDistance(const Point3D* p1, const Point3D* p2);
void printDistance(double distance);

int main(void) {
    Point3D point1, point2; // Variables to store the two points

    // Input coordinates for the two points
    inputPoints(&point1, &point2);

    // Calculate the distance between the two points
    double distance = calculateDistance(&point1, &point2);

    // Print the calculated distance
    printDistance(distance);

    return 0;
}

// Function to input coordinates for two 3D points
void inputPoints(Point3D* p1, Point3D* p2) {
    printf("Enter the coordinates for the first point (x y z): ");
    scanf("%lf %lf %lf", &p1->x, &p1->y, &p1->z);

    printf("Enter the coordinates for the second point (x y z): ");
    scanf("%lf %lf %lf", &p2->x, &p2->y, &p2->z);
}

// Function to calculate the Euclidean distance between two 3D points
double calculateDistance(const Point3D* p1, const Point3D* p2) {
    double dx = p2->x - p1->x; // Difference in X-coordinates
    double dy = p2->y - p1->y; // Difference in Y-coordinates
    double dz = p2->z - p1->z; // Difference in Z-coordinates
    return sqrt(dx * dx + dy * dy + dz * dz); // Euclidean distance formula
}

// Function to print the distance between two points
void printDistance(double distance) {
    printf("The distance between the two points is: %.2lf\n", distance);
}