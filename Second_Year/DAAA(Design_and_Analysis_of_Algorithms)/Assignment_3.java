import java.util.Random;
import java.util.Scanner;

public class Assignment_3 {

    public static void merge(int[] arr, int left, int mid, int right) {
        int n1 = mid - left + 1;
        int n2 = right - mid;

        int[] L = new int[n1];
        int[] R = new int[n2];

        for (int i = 0; i < n1; i++)
            L[i] = arr[left + i];
        for (int j = 0; j < n2; j++)
            R[j] = arr[mid + 1 + j];

        int i = 0, j = 0, k = left;

        while (i < n1 && j < n2) {
            if (L[i] <= R[j]) arr[k++] = L[i++];
            else arr[k++] = R[j++];
        }

        while (i < n1) arr[k++] = L[i++];
        while (j < n2) arr[k++] = R[j++];
    }

    public static void mergeSort(int[] arr, int left, int right, String indent) {
        if (left < right) {
            long startTime = System.currentTimeMillis();

            System.out.println(indent + "|--> mergeSort: [" + left + "," + right + "]");

            int mid = (left + right) / 2;
            mergeSort(arr, left, mid, indent + "     ");
            mergeSort(arr, mid + 1, right, indent + "     ");

            merge(arr, left, mid, right);

            long endTime = System.currentTimeMillis();
            System.out.println(indent + "| merge: [" + left + "," + right + "] "
                    + "Time: " + (endTime - startTime) + " ms");
        } else {
            System.out.println(indent + "| mergeSort: [" + left + "," + right + "]");
        }
    }

    public static void printArray(int[] arr) {
        for (int num : arr)
            System.out.print(num + " ");
        System.out.println();
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        Random rand = new Random();

        System.out.print("Enter the number of elements: ");
        int n = sc.nextInt();
        int[] arr = new int[n];

        System.out.print("Enter 1 to input elements manually, 2 for random elements: ");
        int choice = sc.nextInt();

        if (choice == 1) {
            System.out.println("Enter the elements:");
            for (int i = 0; i < n; i++)
                arr[i] = sc.nextInt();
        } else {
            for (int i = 0; i < n; i++)
                arr[i] = rand.nextInt(1001); // random 0-1000
            System.out.println("Randomly generated array:");
            printArray(arr);
        }

        System.out.println("\nOriginal Array:");
        printArray(arr);

        System.out.println("\nMerge Sort Trace:");
        long totalStartTime = System.currentTimeMillis();
        mergeSort(arr, 0, n - 1, "");
        long totalEndTime = System.currentTimeMillis();

        System.out.println("\nSorted Array:");
        printArray(arr);

        System.out.println("\nTotal Time Taken: " + (totalEndTime - totalStartTime) + " ms");
    }
}