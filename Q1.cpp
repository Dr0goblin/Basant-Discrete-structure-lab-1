#include <stdio.h>
void unionSets(int set1[], int set2[], int size1, int size2);
void intersectionSets(int set1[], int set2[], int size1, int size2);
void differenceSets(int set1[], int set2[], int size1, int size2);
void symmetricDifferenceSets(int set1[], int set2[], int size1, int size2);
int isPresent(int set[], int size, int element);

int main() {
    int set1[] = {1, 2, 3, 4, 5};
    int set2[] = {4, 5, 6, 7, 8};
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

    printf("Union: ");
    unionSets(set1, set2, size1, size2);

    printf("Intersection: ");
    intersectionSets(set1, set2, size1, size2);

    printf("Difference (Set 1 - Set 2): ");
    differenceSets(set1, set2, size1, size2);

    printf("Symmetric Difference: ");
    symmetricDifferenceSets(set1, set2, size1, size2);

    return 0;
}

void unionSets(int set1[], int set2[], int size1, int size2) {
    for (int i = 0; i < size1; i++) {
        printf("%d ", set1[i]);
    }
    for (int i = 0; i < size2; i++) {
        if (!isPresent(set1, size1, set2[i])) {
            printf("%d ", set2[i]);
        }
    }
    printf("\n");
}

void intersectionSets(int set1[], int set2[], int size1, int size2) {
    for (int i = 0; i < size1; i++) {
        if (isPresent(set2, size2, set1[i])) {
            printf("%d ", set1[i]);
        }
    }
    printf("\n");
}

void differenceSets(int set1[], int set2[], int size1, int size2) {
    for (int i = 0; i < size1; i++) {
        if (!isPresent(set2, size2, set1[i])) {
            printf("%d ", set1[i]);
        }
    }
    printf("\n");
}

void symmetricDifferenceSets(int set1[], int set2[], int size1, int size2) {
    for (int i = 0; i < size1; i++) {
        if (!isPresent(set2, size2, set1[i])) {
            printf("%d ", set1[i]);
        }
    }
    for (int i = 0; i < size2; i++) {
        if (!isPresent(set1, size1, set2[i])) {
            printf("%d ", set2[i]);
        }
    }
    printf("\n");
}

int isPresent(int set[], int size, int element) {
    for (int i = 0; i < size; i++) {
        if (set[i] == element) {
            return 1;
        }
    }
    return 0;
}
