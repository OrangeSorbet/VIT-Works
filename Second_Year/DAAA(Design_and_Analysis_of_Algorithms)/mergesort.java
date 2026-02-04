import java.util.ArrayList;
import java.util.Scanner;

public class mergesort {

    public static void merge(ArrayList<Integer> arr, int low, int mid, int high) {
        ArrayList<Integer> temp = new ArrayList<>();
        int i = low, j = mid + 1;

        while (i <= mid && j <= high) {
            if (arr.get(i) <= arr.get(j)) {
                temp.add(arr.get(i));
                i++;
            } else {
                temp.add(arr.get(j));
                j++;
            }
        }

        while (i <= mid) {
            temp.add(arr.get(i));
            i++;
        }

        while (j <= high) {
            temp.add(arr.get(j));
            j++;
        }

        for (int k = 0; k < temp.size(); k++) {
            arr.set(low + k, temp.get(k));
        }
    }

    public static void merge_sort(ArrayList<Integer> arr, int low, int high) {
        if (low < high) {
            int mid = (low + high) / 2;
            merge_sort(arr, low, mid);
            merge_sort(arr, mid + 1, high);
            merge(arr, low, mid, high);
        }
    }

    public static void main(String args[]) {
        ArrayList<Integer> arr = new ArrayList<>();
        System.out.println("Enter numbers and then a non-number to end - ");

        try (Scanner scan = new Scanner(System.in)) {
            while (scan.hasNextInt()) {
                arr.add(scan.nextInt());
            }
        }

        merge_sort(arr, 0, arr.size() - 1);
        System.out.println(arr);
    }
}