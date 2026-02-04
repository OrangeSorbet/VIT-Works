import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;

public class quicksort {
    public static int partition(ArrayList<Integer> arr, int low, int high) {
        int pivot = arr.get(high);
        int i = low - 1;
        for(int j = low; j < high; j++) {
            if(arr.get(j) < pivot) {
                i++;
                Collections.swap(arr, i, j);
            }
        }
        Collections.swap(arr, i+1, high);
        return(i+1);
    }

    public static void quick_sort(ArrayList<Integer> arr, int low, int high) {
        if (low < high) {
            int pi = partition(arr, low, high);
            quick_sort(arr, low, pi-1);
            quick_sort(arr, pi+1, high);
        }
    }
    public static void main(String args[]) {
        ArrayList<Integer> arr = new ArrayList<>();
        System.out.print("Enter numbers and a non-number to end the array - ");
        try(Scanner scan = new Scanner(System.in)) {
            while (scan.hasNextInt()) { 
                arr.add(scan.nextInt());
            }
        }
        int low = 0;
        int high = arr.size() - 1;
        quick_sort(arr, low, high);
        System.out.print(arr);
    }
}
