#include <stdio.h>
#include <string.h>

// Function to convert decimal to binary (8-bit)
void decimalToBinary(int n, char binary[9]) {
    for (int i = 7; i >= 0; i--) {
        if (n % 2 == 0) {
            binary[i] = '0';
        } else {
            binary[i] = '1';
        }
        n = n / 2;
    }
    binary[8] = '\0'; // Null-terminate the string
}

// Function to convert a 16-bit binary number to decimal
int binaryToDecimal16(char binary[17]) {
    int decimal = 0;
    int power = 1;

    // Check if the number is negative (two's complement representation)
    if (binary[0] == '1') {
        // Find two's complement to get the positive equivalent
        char complementBinary[17];
        for (int i = 0; i < 16; i++) {
            if (binary[i] == '0') {
                complementBinary[i] = '1';
            } else {
                complementBinary[i] = '0';
            }
        }
        complementBinary[16] = '\0';

        // Add 1 to the one's complement
        char one[17] = "0000000000000001";
        char temp[17];
        int carry = 0;
        for (int i = 15; i >= 0; i--) {
            int sum = (complementBinary[i] - '0') + (one[i] - '0') + carry;
            if (sum == 2) {
                temp[i] = '0';
                carry = 1;
            } else if (sum == 3) {
                temp[i] = '1';
                carry = 1;
            } else {
                temp[i] = sum + '0';
                carry = 0;
            }
        }
        temp[16] = '\0';

        // Convert the positive equivalent to decimal
        for (int i = 15; i >= 0; i--) {
            if (temp[i] == '1') {
                decimal += power;
            }
            power *= 2;
        }

        // Return the negative value
        return -decimal;
    } else {
        // Convert directly for positive numbers
        for (int i = 15; i >= 0; i--) {
            if (binary[i] == '1') {
                decimal += power;
            }
            power *= 2;
        }
    }

    return decimal;
}

// Function to add two binary numbers (8 bits)
void add(char A[9], char M[9], char result[9]) {
    int carry = 0;
    for (int i = 7; i >= 0; i--) {
        int sum = (A[i] - '0') + (M[i] - '0') + carry;
        if (sum == 2) {
            result[i] = '0';
            carry = 1;
        } else if (sum == 3) {
            result[i] = '1';
            carry = 1;
        } else {
            result[i] = sum + '0';
            carry = 0;
        }
    }
    result[8] = '\0'; // Null-terminate the string
}

// Function to find the two's complement of a binary number
void twosComplement(char m[9], char result[9]) {
    // Find one's complement
    for (int i = 0; i < 8; i++) {
        if (m[i] == '0') {
            result[i] = '1';
        } else {
            result[i] = '0';
        }
    }
    result[8] = '\0'; // Null-terminate the string

    // Add 1 to the one's complement
    char one[9] = "00000001";
    add(result, one, result);
}

// Function to perform Booth's Multiplication Algorithm
void boothsAlgorithm(char M[9], char Q[9], char result[17]) {
    char A[9] = "00000000"; // Accumulator initialized to zero
    char Q_1 = '0';         // Q-1 initialized to zero
    int count = 8;          // Number of bits

    printf("Initial Values: A: %s Q: %s Q-1: %c M: %s\n", A, Q, Q_1, M);

    while (count > 0) {
        printf("\nStep %d:\n", 9 - count);

        // Check the last bit of Q and Q-1
        if (Q[7] == '1' && Q_1 == '0') {
            // A = A - M
            char comp_M[9];
            twosComplement(M, comp_M);
            add(A, comp_M, A);
            printf("A = A - M -> A: %s\n", A);
        } else if (Q[7] == '0' && Q_1 == '1') {
            // A = A + M
            add(A, M, A);
            printf("A = A + M -> A: %s\n", A);
        }

        // Arithmetic right shift of [A, Q, Q-1]
        Q_1 = Q[7]; // Save the last bit of Q as Q-1
        for (int i = 7; i > 0; i--) {
            Q[i] = Q[i - 1];
        }

		Q[0] = A[7]; // The last bit of A becomes the first bit of Q

		for (int i = 7; i > 0; i--) {
			A[i] = A[i - 1];
		}

		printf("After Arithmetic Right Shift -> A: %s Q: %s Q-1: %c\n", A, Q, Q_1);

		count--;
	}

	// Combine final values of A and Q into a single result
	strncpy(result, A, 8);       // Copy accumulator into the first half of the result
	strncpy(result + 8, Q, 8);   // Copy multiplier into the second half of the result
	result[16] = '\0';           // Null-terminate the result

	printf("\nFinal Values:\n");
	printf("A: %s\n", A);
	printf("Q: %s\n", Q);
}

// Main function to test Booth's Algorithm
int main() {
	int multiplicandDecimal, multiplierDecimal;

	// User input for multiplicand and multiplier
	printf("Enter the multiplicand (decimal): ");
	scanf("%d", &multiplicandDecimal);

	printf("Enter the multiplier (decimal): ");
	scanf("%d", &multiplierDecimal);

	// Ensure inputs are within signed range (-128 to +127)
	if ((multiplicandDecimal < -128 || multiplicandDecimal > 127) ||
		(multiplierDecimal < -128 || multiplierDecimal > 127)) {
		printf("Error: Please enter values between -128 and +127.\n");
		return -1;
	}

	// Convert inputs to binary format
	char multiplicandBinary[9], multiplierBinary[9];

	if (multiplicandDecimal < 0) {
	    decimalToBinary(multiplicandDecimal + 256, multiplicandBinary);
	} else {
	    decimalToBinary(multiplicandDecimal, multiplicandBinary);
	}

	if (multiplierDecimal < 0) {
	    decimalToBinary(multiplierDecimal + 256, multiplierBinary);
	} else {
	    decimalToBinary(multiplierDecimal, multiplierBinary);
	}

	printf("Binary Multiplicand: %s\n", multiplicandBinary);
	printf("Binary Multiplier:   %s\n", multiplierBinary);

	// Perform Booth's Multiplication Algorithm
	char productBinary[17];
	boothsAlgorithm(multiplicandBinary, multiplierBinary, productBinary);

	// Convert final product from binary to decimal and display results
	int productDecimal;

	productDecimal= binaryToDecimal16(productBinary);

	printf("\nFinal Product (Binary): ");
	for(int i=0; i<16; ++i) {
	    printf("%c", productBinary[i]);
	}
	printf("\nFinal Product (Decimal): %d\n", productDecimal);

	return 0;
}
