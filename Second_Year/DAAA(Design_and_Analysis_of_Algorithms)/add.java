import java.util.Scanner;

public class add {
    public static void adder(int a, int b) {
        int sum = a + b;
        System.out.println(a + " + " + b + " = " + sum);
    }

    public static void main(String[] args) {
        System.out.print("Enter two numbers to add: ");

        try (Scanner scan = new Scanner(System.in)) {
            int num1 = scan.nextInt();
            int num2 = scan.nextInt();
            adder(num1, num2);
            scan.close();
        }
    }
}
