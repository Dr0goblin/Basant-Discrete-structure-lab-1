#include <stdio.h>
#include <math.h>

int main() {
    double num;
    int floorValue, ceilingValue;

    // Read input from the user
    printf("Enter a real number: ");
    scanf("%lf", &num);

    // Calculate floor and ceiling values
    floorValue = (int)floor(num);
    ceilingValue = (int)ceil(num);

    // Print the results
    printf("Floor: %d\n", floorValue);
    printf("Ceiling: %d\n", ceilingValue);

    return 0;
}
