#include <stdio.h>
#include <stdlib.h>

int main() {
    // Menu Part
    int n;

    printf("Enter the number of elements: ");
    while(scanf("%d", &n) != 1 || n <= 0) {
        printf("Invalid input. Please enter a positive integer - ");
        while(getchar() != '\n');
        continue;
    }

    int *arr = (int *)malloc(n * sizeof(int));
    int ele = 0;

    for (int i = 0; i < n; i++) {
        printf("Element %d: ", i + 1);
        if(scanf("%d", &ele) != 1 || ele < 0) {
            printf("Invalid input. Please enter integers only - ");
            while(getchar() != '\n');
            i--;
            continue;
        } else {
            arr[i] = ele;
        }
    }

    printf("\nArray before sorting:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Sorting Part - Insertion Sort
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }

    printf("\nArray after sorting (Insertion Sort):\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    free(arr);
}