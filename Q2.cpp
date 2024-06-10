#include <stdio.h>

// Function prototype
void cartesianProduct(int set1[], int set2[], int size1, int size2);

int main() {
    int set1[] = {1, 2, 3};
    int set2[] = {4, 5, 6};
    int size1 = sizeof(set1) / sizeof(set1[0]);
    int size2 = sizeof(set2) / sizeof(set2[0]);

    printf("Set 1: ");
    for (int i = 0; i < size1; i++) {
        printf("%d ", set1[i]);
    }
    printf("\n");

    printf("Set 2: ");
    for (int i = 0; i < size2; i++) {
        printf("%d ", set2[i]);
    }
    printf("\n");

    printf("Cartesian Product: \n");
    cartesianProduct(set1, set2, size1, size2);

    return 0;
}

void cartesianProduct(int set1[], int set2[], int size1, int size2) {
    for (int i = 0; i < size1; i++) {
        for (int j = 0; j < size2; j++) {
            printf("(%d, %d) ", set1[i], set2[j]);
        }
        printf("\n");
    }
}
