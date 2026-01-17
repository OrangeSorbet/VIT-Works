#include <stdio.h>
#include <stdlib.h>

void printPointer(int *arr, int size) {
    printf("Array elements are:\n");
    for (int i = 0; i < size; i++) {
        printf("%d", *(arr + i));
        if(i<size-1)
            printf(", ");
    }
    printf("\n");
}

void printDynamic(int size) {
    int *arr = (int *)malloc(size * sizeof(int));

    if (arr == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }

    printf("Enter %d elements:\n", size);
    for (int i = 0; i < size; i++) {
        scanf("%d", (arr + i));
    }

    printf("Dynamically allocated array elements are:\n");
    for (int i = 0; i < size; i++) {
        printf("%d", *(arr + i));
        if(i<size-1)
            printf(", ");
    }
    printf("\n");

    free(arr); // Free dynamically allocated memory
}

int main() {
    int choice, size;
    int arr[100];

    do {
        printf("---------------------------------\n");
        printf("Array Operations Using Pointers\n");
        printf("---------------------------------\n");
        printf("1. Accept and Print Array Elements using pointer.\n");
        printf("2. Accept and Print Array Elements using Dynamic Memory Allocation.\n");
        printf("3. Exit\n");
        printf("---------------------------------\n");
        printf("Enter your choice - ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the number of elements in the array: ");
                scanf("%d", &size);

                printf("Enter %d elements:\n", size);
                for (int i = 0; i < size; i++) {
                    scanf("%d", (arr + i));
                }

                printPointer(arr, size);
                break;

            case 2:
                printf("Enter the number of elements for dynamic array: ");
                scanf("%d", &size);

                printDynamic(size);
                break;

            case 3:
                printf("Exiting program\n");
                break;

            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 3);

    return 0;
}
