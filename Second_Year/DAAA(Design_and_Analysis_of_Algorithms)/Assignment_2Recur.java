import java.util.*;

public class Assignment_2Recur {

    static int comparisons = 0;

    static void bubbleSort(ArrayList<Integer> list) {
        int n = list.size();
        for(int i = 0; i < n - 1; i++) {
            for(int j = 0; j < n - 1 - i; j++) {
                if(list.get(j) > list.get(j + 1)) {
                    int temp = list.get(j);
                    list.set(j, list.get(j + 1));
                    list.set(j + 1, temp);
                }
            }
        }
    }

    static int binarySearch(ArrayList<Integer> list, int left, int right, int target) {
        if(left > right) {
            return -1;
        }

        int mid = left + (right - left) / 2;

        comparisons++;
        if(list.get(mid) == target) {
            return mid;
        }

        comparisons++;
        if(list.get(mid) < target) {
            return binarySearch(list, mid + 1, right, target);
        } else {
            return binarySearch(list, left, mid - 1, target);
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        ArrayList<Integer> list = new ArrayList<>();

        System.out.println("Binary Search (Recursive)");
        System.out.print("Enter number of elements: ");
        int n = sc.nextInt();

        System.out.println("Enter " + n + " elements:");
        for(int i = 0; i < n; i++) {
            list.add(sc.nextInt());
        }

        System.out.println("Unsorted Array: " + list);

        bubbleSort(list);

        System.out.println("Sorted Array: " + list);

        System.out.print("Enter element to search: ");
        int target = sc.nextInt();

        comparisons = 0;
        int result = binarySearch(list, 0, list.size() - 1, target);

        if(result == -1) {
            System.out.println("Element not found");
        } else {
            System.out.println("Element found at index: " + result);
        }

        System.out.println("Number of comparisons: " + comparisons);

        sc.close();
    }
}