
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Scanner;

public class comparemany {
    public static int[] comparer2(ArrayList<Integer> num) {
        if(num.isEmpty()) return new int[]{0, 0};
        int maxn = num.get(0);
        int minn = num.get(0);
        for (int i : num) {
            if(i < minn) minn = i;
            if(i > maxn) maxn = i;
        }

        return new int[]{maxn, minn};
    }

    public static void main(String[] args) {
        ArrayList<Integer> num = new ArrayList<>();
        
        System.out.print("Enter numbers and then any non-number (like 'a') to finish - ");
        try(Scanner scan = new Scanner(System.in)) {
            while(scan.hasNextInt()) {
                num.add(scan.nextInt());
            }
            scan.close();
        }
        
        int[] result = comparer2(num);
        if(Arrays.equals(result, new int[]{0, 0})) System.out.println ("No numbers entered!");
        else {
            System.out.println("Max number is " + result[0]);
            System.out.println("Min number is " + result[1]);
        }
    }
}