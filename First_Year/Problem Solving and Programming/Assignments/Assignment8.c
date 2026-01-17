#include <stdio.h>
#include <math.h>
#include <stdbool.h>

int choice, base, n, num, rem, dec=0, total=0, i, j, k, l, digit, result, original_num;
int n1, n2, prime[50];

int power(base, n)
{
    if(n>0)
        return base*power(base, n-1);
    else if(n<0)
        return 1/base*power(base, n+1);
    else
        return 1;
}

int main() {
do {
    //menu
    printf("---------------------------------\n");
    printf("1. Print power of a number\n");
    printf("2. Display all prime numbers between two intervals\n");
    printf("3. Convert decimal to binary number\n");
    printf("4. Exit\n");
    printf("---------------------------------\n");
    printf("Enter your choice - ");
    scanf("%d", &choice);

    //switch
    switch (choice)
    {
    case 1:
        printf("Enter a base number - ");
        scanf("%d", &base);
        printf("Enter the power (any whole number) - ");
        scanf("%d", &n);
        result = power(base, n);
        printf("%d^%d = %d\n", base, n, result);
        break;

    case 2:
        printf("Enter the first number - ");
        scanf("%d", &n1);
        printf("Enter the second number - ");
        scanf("%d", &n2);

        // Prime checking and storing primes in the array
        for (i = n1; i <= n2; i++) {
        bool isPrime = true;

        // Skip 1 as it's not prime
        if (i <= 1) {
            continue;
        }

        // Check if 'i' is divisible by any number other than 1 and itself
        for (j = 2; j * j <= i; j++) {
            if (i % j == 0) {
                isPrime = false;
                break;
            }
        }

        // If it's a prime number, store it in the prime array
        if (isPrime) {
            prime[k] = i;
            k++;
        }
    }

    // Display the prime numbers
    printf("Prime numbers between %d and %d are:\n", n1, n2);
    for (i = 0; i < k; i++) {
        if(i!=0)
            printf(", ");
        printf("%d", prime[i]);
    }
    printf("\n");
    i=j=k=l=n1=n2=0;
        break;

    case 3:
        case3:
    printf("Enter a binary number to convert into decimal: ");
    scanf("%d", &num);

    // Store the original number for later use in output
    original_num = num;

    // Validate the binary input
    int isValidBinary = 1; // Flag to check if the input is valid binary

    // Check if each digit is either 0 or 1
    int temp = num;
    while (temp != 0) {
        rem = temp % 10;
        if (rem != 0 && rem != 1) {
            isValidBinary = 0;
            break;
        }
        temp = temp / 10;
    }

    if (isValidBinary == 0) {
        printf("This is not a binary number.\n");
        goto case3;  // Exit the program if invalid binary number
    }

    // If valid binary, convert to decimal
    num = original_num; // Reset num to original for conversion
    while (num != 0) {
        rem = num % 10;  // Get the last digit (either 0 or 1)
        dec += rem * pow(2, i);  // Convert binary to decimal
        num /= 10;  // Remove the last digit
        i++;  // Increment the power of 2
    }

    // Output the decimal equivalent
    printf("Decimal form of %d is: %d\n", original_num, dec);
    break;

    case 4:
        exit(0);
        break;
    }
}
while(choice!=4);
getch();
}
