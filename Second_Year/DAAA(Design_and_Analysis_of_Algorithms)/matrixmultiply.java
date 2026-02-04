import java.util.Scanner;

class Matrix {
    int m, n;
    int[][] data;

    Matrix(int m, int n, Scanner sc) {
        this.m = m;
        this.n = n;
        data = new int[m][n];

        System.out.println("Enter elements for matrix (" + m + "x" + n + "):");
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                data[i][j] = sc.nextInt();
            }
        }
    }

    void display() {
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                System.out.print(data[i][j] + " ");
            }
            System.out.println();
        }
    }
}

public class matrixmultiply {

    static int[][] multiplier(Matrix A, Matrix B) {
        int[][] result = new int[A.m][B.n];

        for (int i = 0; i < A.m; i++) {
            for (int j = 0; j < B.n; j++) {
                for (int k = 0; k < A.n; k++) {
                    result[i][j] += A.data[i][k] * B.data[k][j];
                }
            }
        }
        return result;
    }

    static void displayResult(int[][] result) {
        for (int[] row : result) {
            for (int val : row) {
                System.out.print(val + " ");
            }
            System.out.println();
        }
    }

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);
        System.out.print("Enter dimensions (a b c d, where b = c): ");

        int m = sc.nextInt();
        int n = sc.nextInt();
        int a = sc.nextInt();
        int b = sc.nextInt();

        if (n != a) {
            System.out.println("Matrix multiplication not possible.");
            return;
        }

        Matrix A = new Matrix(m, n, sc);
        Matrix B = new Matrix(a, b, sc);

        int[][] result = multiplier(A, B);

        System.out.println("Matrix A:");
        A.display();

        System.out.println("Matrix B:");
        B.display();

        System.out.println("Result matrix:");
        displayResult(result);
    }
}