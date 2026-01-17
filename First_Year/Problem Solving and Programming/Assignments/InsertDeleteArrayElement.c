#include <stdio.h>
#include <stdlib.h>

void read(int *arr, int size) {
    printf("Enter elements: ");
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }
}

void display(int *arr, int size) {
    printf("Array: [");
    for (int i = 0; i < size; i++) {
        printf("%d", arr[i]);
        if (i < size - 1)
            printf(", ");
    }
    printf("]\n");
}

void insert(int **arr, int *size) {
    *arr = realloc(*arr, (*size + 1) * sizeof(int));  // Reallocate memory for one more element
    if (*arr == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);  // Exit if reallocation fails
    }
    printf("Insert element: ");
    scanf("%d", &(*arr)[*size]);  // Insert the element at the new position
    (*size)++;  // Increment the size
}

void delete(int **arr, int *size, int index) {
    if (index < 0 || index >= *size) {
        printf("Invalid index.\n");
        return;
    }

    // Shift elements left to remove the element at index
    for (int i = index; i < *size - 1; i++) {
        (*arr)[i] = (*arr)[i + 1];
    }

    // Shrink the array using realloc
    *arr = realloc(*arr, (*size - 1) * sizeof(int));
    if (*arr == NULL && *size > 1) {
        printf("Memory allocation failed.\n");
        exit(1);  // Exit if reallocation fails
    }
    (*size)--;  // Decrement size
}

int main() {
    int *arr1 = NULL;
    int size = 0;
    int choice, index;

    // Initialize the array
    printf("Enter initial size: ");
    scanf("%d", &size);

    if (size < 1) {
        printf("Array size should be at least 1.\n");
        return 1;
    }

    arr1 = (int *)malloc(size * sizeof(int));  // Allocate memory for the array

    if (arr1 == NULL) {
        printf("Memory allocation failed.\n");
        return 1;  // Exit if allocation fails
    }

    // Read the elements into the array
    read(arr1, size);

    while (1) {
        // Menu-driven interface using switch-case
        printf("\nMenu:\n");
        printf("1. Read and print array\n");
        printf("2. Insert element\n");
        printf("3. Delete element\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:  // Read and print array
                display(arr1, size);
                break;

            case 2:  // Insert element
                insert(&arr1, &size);
                break;

            case 3:  // Delete element
                printf("Enter index of element to delete (0 to %d): ", size - 1);
                scanf("%d", &index);
                delete(&arr1, &size, index);
                break;

            case 4:  // Exit
                free(arr1);
                printf("Exiting program.\n");
                return 0;

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
