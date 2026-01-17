#include <stdio.h>

void swap(int *a, int *b) {
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    int num1, num2;

    printf("Enter first number: ");
    scanf("%d", &num1);

    printf("Enter second number: ");
    scanf("%d", &num2);

    printf("Before swapping, first number is %d and second number is %d\n", num1, num2);

    // Call the swap function and pass the addresses of num1 and num2
    swap(&num1, &num2);

    printf("After swapping, first number is %d and second number is %d\n", num1, num2);

    return 0;
}
