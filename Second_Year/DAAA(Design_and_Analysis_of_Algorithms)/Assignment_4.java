import java.util.Arrays;
import java.util.Random;
import java.util.Scanner;

public class Assignment_4 {

    public static void quickSort(int[] arr, int low, int high, int pivotIndex) {
        if (low < high) {
            int pi = partition(arr, low, high, pivotIndex);
            quickSort(arr, low, pi - 1, pivotIndex);
            quickSort(arr, pi + 1, high, pivotIndex);
        }
    }

    private static int partition(int[] arr, int low, int high, int pivotIndex) {
        if (pivotIndex != high) swap(arr, pivotIndex, high);
        int pivot = arr[high];
        int i = low - 1;
        for (int j = low; j < high; j++) {
            if (arr[j] <= pivot) {
                i++;
                swap(arr, i, j);
            }
        }
        swap(arr, i + 1, high);
        return i + 1;
    }

    private static void swap(int[] arr, int i, int j) {
        int tmp = arr[i];
        arr[i] = arr[j];
        arr[j] = tmp;
    }

    public static void mergeSort(int[] arr, int left, int right) {
        int[] temp = new int[arr.length];
        mergeSortHelper(arr, temp, left, right);
    }

    private static void mergeSortHelper(int[] arr, int[] temp, int left, int right) {
        if (left < right) {
            int mid = (left + right) / 2;
            mergeSortHelper(arr, temp, left, mid);
            mergeSortHelper(arr, temp, mid + 1, right);
            merge(arr, temp, left, mid, right);
        }
    }

    private static void merge(int[] arr, int[] temp, int left, int mid, int right) {
        for (int i = left; i <= right; i++) temp[i] = arr[i];

        int i = left, j = mid + 1, k = left;

        while (i <= mid && j <= right) {
            if (temp[i] <= temp[j]) arr[k++] = temp[i++];
            else arr[k++] = temp[j++];
        }

        while (i <= mid) arr[k++] = temp[i++];
        while (j <= right) arr[k++] = temp[j++];
    }

    private static void printArray(String msg, int[] arr) {
        System.out.println(msg);
        for (int num : arr) System.out.print(num + " ");
        System.out.println();
    }

    public static void averageExecutionTimesOption() {
        final int n = 1000000;
        final int iterations = 5;
        Random rand = new Random();

        long totalQuickFirst = 0;
        long totalQuickMiddle = 0;
        long totalQuickLast = 0;
        long totalMerge = 0;

        for (int it = 0; it < iterations; it++) {
            int[] original = new int[n];
            for (int i = 0; i < n; i++) original[i] = rand.nextInt(1001);

            int[] arrQuick = original.clone();
            long start = System.nanoTime();
            quickSort(arrQuick, 0, n - 1, 0);
            long end = System.nanoTime();
            totalQuickFirst += (end - start);

            arrQuick = original.clone();
            start = System.nanoTime();
            quickSort(arrQuick, 0, n - 1, n / 2);
            end = System.nanoTime();
            totalQuickMiddle += (end - start);

            arrQuick = original.clone();
            start = System.nanoTime();
            quickSort(arrQuick, 0, n - 1, n - 1);
            end = System.nanoTime();
            totalQuickLast += (end - start);

            int[] arrMerge = original.clone();
            start = System.nanoTime();
            mergeSort(arrMerge, 0, n - 1);
            end = System.nanoTime();
            totalMerge += (end - start);
        }

        System.out.println("\nAverage Execution Times (µs) over " + iterations + " runs:");
        System.out.println("Quick Sort - First Pivot: " + (totalQuickFirst / iterations) / 1000);
        System.out.println("Quick Sort - Middle Pivot: " + (totalQuickMiddle / iterations) / 1000);
        System.out.println("Quick Sort - Last Pivot: " + (totalQuickLast / iterations) / 1000);
        System.out.println("Merge Sort: " + (totalMerge / iterations) / 1000);
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        Random rand = new Random();

        System.out.println("Choose Option:");
        System.out.println("1. Normal execution (enter array size)");
        System.out.println("2. Average execution times for 100000 elements");
        int mainChoice = sc.nextInt();

        if (mainChoice == 2) {
            averageExecutionTimesOption();
            sc.close();
            return;
        }
        System.out.print("Enter array size: ");
        int n = sc.nextInt();
        int[] original = new int[n];
        for (int i = 0; i < n; i++) original[i] = rand.nextInt(1001);

        System.out.println("\nChoose Data Type:");
        System.out.println("1. Random");
        System.out.println("2. Sorted");
        System.out.println("3. Reverse Sorted");
        int dataChoice = sc.nextInt();
        if (dataChoice == 2) Arrays.sort(original);
        else if (dataChoice == 3) {
            Arrays.sort(original);
            for (int i = 0; i < n / 2; i++) swap(original, i, n - i - 1);
        }

        printArray("\nOriginal Array:", original);

        int[] arrMerge = original.clone();

        System.out.println("\nQuick Sort Options:");
        System.out.println("1. Choose pivot index manually");
        System.out.println("2. Try all pivot indices");
        int quickChoice = sc.nextInt();

        if (quickChoice == 1) {
            System.out.print("Enter pivot index (0 to " + (n - 1) + "): ");
            int pivotIndex = sc.nextInt();
            int[] arrQuick = original.clone();
            long start = System.nanoTime();
            quickSort(arrQuick, 0, n - 1, pivotIndex);
            long end = System.nanoTime();
            printArray("\nSorted Array by Quick Sort:", arrQuick);
            System.out.println("Execution Time: " + (end - start)/1000 + " µs");
        } else {
            System.out.println("\nQuick Sort Execution Times for Each Pivot Index:");
            for (int pivotIndex = 0; pivotIndex < n; pivotIndex++) {
                int[] arrQuick = original.clone();
                long start = System.nanoTime();
                quickSort(arrQuick, 0, n - 1, pivotIndex);
                long end = System.nanoTime();
                System.out.println("Pivot " + pivotIndex + ": " + (end - start)/1000 + " µs");
            }
        }

        long startMerge = System.nanoTime();
        mergeSort(arrMerge, 0, n - 1);
        long endMerge = System.nanoTime();
        printArray("\nSorted Array by Merge Sort:", arrMerge);
        System.out.println("Merge Sort Execution Time: " + (endMerge - startMerge)/1000 + " µs");

        sc.close();
    }
}