#include <stdio.h>

// Define a structure to hold person's data
typedef struct {
    char name[50];
    int age;
    double membership1;
    double membership2;
} Person;

// Function prototypes
double calculateMembership1(int age);
double calculateMembership2(int age);
double fuzzyUnion(double m1, double m2);
double fuzzyIntersection(double m1, double m2);

int main() {
    Person persons[5];
    
    // Input data for 5 persons
    for(int i = 0; i < 5; i++) {
        printf("Enter name of person %d: ", i + 1);
        scanf("%s", persons[i].name);
        printf("Enter age of person %d: ", i + 1);
        scanf("%d", &persons[i].age);
        
        // Calculate degree of membership for both membership functions
        persons[i].membership1 = calculateMembership1(persons[i].age);
        persons[i].membership2 = calculateMembership2(persons[i].age);
    }

    // Display the degree of memberships
    printf("\nName\tAge\tMembership1\tMembership2\tUnion\t\tIntersection\n");
    for(int i = 0; i < 5; i++) {
        double unionMembership = fuzzyUnion(persons[i].membership1, persons[i].membership2);
        double intersectionMembership = fuzzyIntersection(persons[i].membership1, persons[i].membership2);
        printf("%s\t%d\t%.2f\t\t%.2f\t\t%.2f\t\t%.2f\n", 
               persons[i].name, 
               persons[i].age, 
               persons[i].membership1, 
               persons[i].membership2, 
               unionMembership, 
               intersectionMembership);
    }

    return 0;
}

double calculateMembership1(int age) {
    if (age <= 20) {
        return 1.0;
    } else if (age > 20 && age <= 30) {
        return (30.0 - age) / 10.0;
    } else {
        return 0.0;
    }
}

double calculateMembership2(int age) {
    if (age <= 15) {
        return 1.0;
    } else if (age > 15 && age <= 35) {
        return (35.0 - age) / 20.0;
    } else {
        return 0.0;
    }
}

double fuzzyUnion(double m1, double m2) {
    return (m1 > m2) ? m1 : m2;
}

double fuzzyIntersection(double m1, double m2) {
    return (m1 < m2) ? m1 : m2;
}
