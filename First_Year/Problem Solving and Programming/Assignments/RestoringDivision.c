#include <stdio.h>
#include <string.h>

// Function to convert decimal to binary (8-bit)
void decimalToBinary(int n, char binary[9]) {
    for (int i = 7; i >= 0; i--) {
        binary[i] = (n % 2) + '0';
        n = n / 2;
    }
    binary[8] = '\0'; // Null-terminate the string
}

// Function to convert binary to decimal (8-bit)
int binaryToDecimal(char binary[9]) {
    int decimal = 0;
    int power = 1;

    for (int i = 7; i >= 0; i--) {
        if (binary[i] == '1') {
            decimal += power;
        }
        power *= 2;
    }
    return decimal;
}

// Function to add two binary numbers (8 bits)
void add(char A[9], char M[9], char result[9]) {
    int carry = 0;
    for (int i = 7; i >= 0; i--) {
        int temp = (A[i] - '0') + (M[i] - '0') + carry;
        result[i] = (temp % 2) + '0';
        carry = temp / 2;
    }
    result[8] = '\0';  // Null-terminate the result
}

// Function to find the complement of the binary number (8 bits)
void complement(char m[9], char result[9]) {
    for (int i = 0; i < 8; i++) {
        result[i] = (m[i] == '0') ? '1' : '0';
    }
    result[8] = '\0';  // Null-terminate the result

    // Adding 1 to the complement
    char one[9] = "00000001";
    add(result, one, result);
}

// Function to perform Restoring Division (8-bit)
void restoringDivision(char Q[9], char M[9], char A[9]) {
    int count = 8;  // 8-bit division
    char temp[9];

    printf("Initial Values: A:%s Q:%s M:%s\n", A, Q, M);

    while (count > 0) {
        printf("\nStep: %d\n", (9 - count));

        // Left shift A by one bit and add Q[0]
        for (int i = 0; i < 7; i++) {
            A[i] = A[i + 1];
        }
        A[7] = Q[0];

        // Subtract M (by adding its complement)
        char comp_M[9];
        complement(M, comp_M);
        add(A, comp_M, temp);

        // Update A with the result of subtraction
        strcpy(A, temp);

        printf("Left Shift and Subtract: A: %s\n", A);
        printf("A: %s Q: %s_", A, Q + 1);

        if (A[0] == '1') {
            // Unsuccessful subtraction, quotient bit is 0
            for (int i = 0; i < 7; i++) {
                Q[i] = Q[i + 1];
            }
            Q[7] = '0';
            printf(" - Unsuccessful\n");

            // Restoration is required for A
            add(A, M, temp);
            strcpy(A, temp);
            printf("A: %s Q: %s - Restoration\n", A, Q);
        } else {
            // Successful subtraction, quotient bit is 1
            for (int i = 0; i < 7; i++) {
                Q[i] = Q[i + 1];
            }
            Q[7] = '1';
            printf(" Successful\n");
            printf("A: %s Q: %s - No Restoration\n", A, Q);
        }
        count--;
    }

    // Final quotient and remainder
    printf("\nQuotient(Q): %s Remainder(A): %s\n", Q, A);
}

int main() {
    int dividendDecimal, divisorDecimal;

    // User input for dividend and divisor
    printf("Enter the dividend (decimal): ");
    scanf("%d", &dividendDecimal);
    printf("Enter the divisor (decimal): ");
    scanf("%d", &divisorDecimal);

    // Ensure the input is within the 8-bit range
    if (dividendDecimal < 0 || dividendDecimal > 255 || divisorDecimal < 0 || divisorDecimal > 255) {
        printf("Error: Please enter values between 0 and 255 for 8-bit operations.\n");
        return 1;
    }

    // Convert to 8-bit binary
    char dividendBinary[9], divisorBinary[9];
    decimalToBinary(dividendDecimal, dividendBinary);
    decimalToBinary(divisorDecimal, divisorBinary);

    printf("Binary Dividend: %s\n", dividendBinary);
    printf("Binary Divisor: %s\n", divisorBinary);

    // Initialize accumulator with '0's of the same length as the dividend
    char accumulator[9] = "00000000";  // Initialize accumulator with '0's

    // Perform Restoring Division
    restoringDivision(dividendBinary, divisorBinary, accumulator);

    // Convert final quotient and remainder to decimal and display
    int quotientDecimal = binaryToDecimal(dividendBinary);  // final quotient
    int remainderDecimal = binaryToDecimal(accumulator);   // final remainder

    printf("\nDecimal Results:\n");
    printf("Quotient (Decimal): %d\n", quotientDecimal);
    printf("Remainder (Decimal): %d\n", remainderDecimal);

    return 0;
}
