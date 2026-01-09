import java.util.Scanner;

public class compare {
    public static void comparer(int a, int b) {
        int c = a-b;
        if (c > 0) {
            System.out.println(a + " > " + b);
        } else if (c < 0) {
            System.out.println(a + " < " + b);
        } else {
            System.out.println(a + " and " + b + " are equal");
        }
    }

    public static void main(String[] args) {
        System.out.print("Enter two numbers to compare: ");
        try (Scanner scan = new Scanner(System.in)) {
            int num1 = scan.nextInt();
            int num2 = scan.nextInt();
            comparer(num1, num2);
            scan.close();
        }
    }
}
