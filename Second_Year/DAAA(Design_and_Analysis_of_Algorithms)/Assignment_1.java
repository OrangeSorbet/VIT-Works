import java.util.ArrayList;
import java.util.Scanner;

public class Assignment_1 {

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);
        ArrayList<Integer> arr = new ArrayList<>();

        System.out.print("Enter number of elements: ");
        int n = sc.nextInt();

        if (n <= 0) {
            System.out.println("Array is empty!");
            return;
        }

        System.out.println("Enter elements:");
        for (int i = 0; i < n; i++) {
            arr.add(sc.nextInt());
        }

        long startTime = System.nanoTime();

        int min = arr.get(0);
        int max = arr.get(0);

        for (int i = 1; i < n; i++) {
            if (arr.get(i) < min)
                min = arr.get(i);
            if (arr.get(i) > max)
                max = arr.get(i);
        }

        long endTime = System.nanoTime();
        long duration = endTime - startTime;

        System.out.println("\nMinimum element: " + min);
        System.out.println("Maximum element: " + max);

        System.out.println("Execution time: " + duration + " nanoseconds");

        // Approximate storage calculation
        int storage = (n * Integer.BYTES) + Integer.BYTES * 3;
        System.out.println("Approximate storage used: " + storage + " bytes");

        sc.close();
    }
}
