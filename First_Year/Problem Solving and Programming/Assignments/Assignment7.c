#include <stdio.h>

int choice, row1, row2, col1, col2, matrix1[5][5], matrix2[5][5], result[5][5];

void read(int matrix[5][5], int *row, int *col) {
    printf("Enter number of rows of matrix - ");
    scanf("%d", row);
    printf("Enter number of columns of matrix - ");
    scanf("%d", col);
    printf("Enter numbers in matrix and press enter after each number - \n");
    for (int i = 0; i < *row; i++)
        for (int j = 0; j < *col; j++)
            scanf("%d", &matrix[i][j]);
}

void display(int matrix[5][5], int row, int col) {
    printf("{\n");
    for (int i = 0; i < row; i++) {
        printf("  [");
        for (int j = 0; j < col; j++) {
            printf("%d", matrix[i][j]);
            if (j < col - 1)
                printf(", ");
        }
        printf("]");
        if (i < row - 1)
            printf("\n");
    }
    printf("\n}\n");
}

void reset(int matrix[5][5], int row, int col) {
    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++)
            matrix[i][j] = 0;
}

int main() {
    do {
        // Menu
        printf("---------------------------------\n");
        printf("1. Addition of 2 matrices.\n");
        printf("2. Product of 2 matrices.\n");
        printf("3. Transpose of matrix\n");
        printf("4. Exit\n");
        printf("---------------------------------\n");
        printf("Enter your choice - ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                // Addition
                read(matrix1, &row1, &col1);
                read(matrix2, &row2, &col2);
                if (row1 == row2 && col1 == col2) {
                    printf("Inputted matrix 1 is - \n");
                    display(matrix1, row1, col1);
                    printf("Inputted matrix 2 is - \n");
                    display(matrix2, row2, col2);

                    for (int i = 0; i < row1; i++)
                        for (int j = 0; j < col1; j++)
                            result[i][j] = matrix1[i][j] + matrix2[i][j];

                    printf("Addition of matrix 1 and 2 is - \n");
                    display(result, row1, col1);
                } else {
                    printf("Addition is not possible!\n");
                }
                break;

            case 2:
                // Product
                read(matrix1, &row1, &col1);
                read(matrix2, &row2, &col2);
                if (col1 == row2) {
                    reset(result, row1, col2); // Resetting result to zero

                    printf("Inputted matrix 1 is - \n");
                    display(matrix1, row1, col1);
                    printf("Inputted matrix 2 is - \n");
                    display(matrix2, row2, col2);

                    for (int i = 0; i < row1; i++)
                        for (int j = 0; j < col2; j++)
                            for (int k = 0; k < col1; k++)
                                result[i][j] += matrix1[i][k] * matrix2[k][j];

                    printf("Product of matrix 1 and 2 is - \n");
                    display(result, row1, col2);
                } else {
                    printf("Multiplication is not possible!\n");
                }
                break;

            case 3:
                // Transpose
                read(matrix1, &row1, &col1);
                printf("Inputted matrix is - \n");
                display(matrix1, row1, col1);

                // Transpose
                for (int i = 0; i < row1; i++)
                    for (int j = 0; j < col1; j++)
                        result[j][i] = matrix1[i][j];

                printf("Transpose of the matrix is - \n");
                display(result, col1, row1);
                reset(matrix1, row1, col1);
                reset(matrix2, row2, col2);
                reset(result, col1, row2);
                break;

            case 4:
                return 0;

            default:
                printf("Invalid choice! Please select a valid option.\n");
                break;
        }
    } while (choice != 4);

    return 0;
}
