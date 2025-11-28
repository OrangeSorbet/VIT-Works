#include <stdio.h>
#include <stdlib.h>
#include "12.Sort.h"

int main() {
    printf("Sorting Algorithms Assignment\n");
    printf("----------------------------\n");
    printf("1. Bubble Sort\n");
    printf("2. Selection Sort\n");
    printf("3. Insertion Sort\n");
    printf("4. Merge Sort\n");
    printf("5. Quick Sort\n");

    int choice;
    printf("Enter choice (1-5): ");
    if(scanf("%d", &choice) != 1 || choice < 1 || choice > 5) {
        printf("Invalid input. Please enter a number between 1 and 5.\n");
        while(getchar() != '\n');
        return 1;
    }

    printf("Enter number of elements: ");
    int n;
    if(scanf("%d", &n) != 1 || n <= 0) {
        printf("Invalid input. Please enter a positive integer for number of elements.\n");
        while(getchar() != '\n');
        return 1;
    }

    int *arr = (int *)malloc(n * sizeof(int));

    printf("Enter %d elements:\n", n);
    for(int i = 0; i < n; i++) {
        if(scanf("%d", &arr[i]) != 1) {
            printf("Invalid input. Please enter integers only.\n");
            while(getchar() != '\n')
            continue;
        }
    }

    switch(choice) {
        case 1:
            bubble_sort(arr, n);
            break;
        case 2:
            selection_sort(arr, n);
            break;
        case 3:
            insertion_sort(arr, n);
            break;
        case 4:
            merge_sort(arr, 0, n - 1);
            break;
        case 5:
            quick_sort(arr, 0, n - 1);
            break;
    }

    printf("Sorted array:\n");
    for(int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    free(arr);
}