#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, again;
    printf("Enter the number of elements: ");
    while (scanf("%d", &n) != 1 || n <= 0) {
        printf("Invalid input. Enter a positive integer: ");
        while (getchar() != '\n');
    }

    int *arr = (int *)malloc(n * sizeof(int));
    if (!arr) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    int ele = 0;
    for (int i = 0; i < n; i++) {
        printf("Element %d: ", i + 1);
        while (scanf("%d", &ele) != 1) {
            printf("Invalid input. Enter an integer: ");
            while (getchar() != '\n');
        }
        arr[i] = ele;
    }

    printf("\nArray before sorting:\n");
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\n");

    // Insertion Sort
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }

    printf("\nArray after sorting:\n");
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\n");

    // Fibonacci Search
    int x;
    printf("\nEnter the element to search: ");
    while (scanf("%d", &x) != 1) {
        printf("Invalid input. Enter an integer: ");
        while (getchar() != '\n');
    }

    long fib2 = 0, fib1 = 1, fib = fib1 + fib2;
    while (fib < n) {
        fib2 = fib1;
        fib1 = fib;
        fib = fib1 + fib2;
    }

    int offset = -1;
    int index = -1;

    while (fib > 1) {
        int i = (offset + fib2 < n - 1) ? (offset + fib2) : (n - 1);

        if (arr[i] < x) {
            fib = fib1;
            fib1 = fib2;
            fib2 = fib - fib1;
            offset = i;
        } else if (arr[i] > x) {
            fib = fib2;
            fib1 = fib1 - fib2;
            fib2 = fib - fib1;
        } else {
            index = i;
            break;
        }
    }

    if (fib1 && offset + 1 < n && arr[offset + 1] == x)
        index = offset + 1;

    if (index >= 0)
        printf("\nElement %d found at index %d.\n", x, index);
    else
        printf("\nElement %d not found.\n", x);

    free(arr);
    return 0;
}