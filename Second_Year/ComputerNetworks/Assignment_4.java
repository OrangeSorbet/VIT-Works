import java.util.Scanner;

class Assignment_4 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.println("1. Checksum");
        System.out.println("2. CRC");
        System.out.println("3. Parity");
        System.out.print("Enter your choice: ");
        int choice = sc.nextInt();

        switch (choice) {

            case 1:
                System.out.print("Enter first binary number: ");
                int a = Integer.parseInt(sc.next(), 2);

                System.out.print("Enter second binary number: ");
                int b = Integer.parseInt(sc.next(), 2);

                int sum = a + b;

                String binarySum = Integer.toBinaryString(sum);

                String checksum = "";
                for (int i = 0; i < binarySum.length(); i++) {
                    if (binarySum.charAt(i) == '1')
                        checksum += "0";
                    else
                        checksum += "1";
                }

                System.out.println("Binary Sum: " + binarySum);
                System.out.println("Checksum: " + checksum);
                break;

            case 2:
                System.out.print("Enter data: ");
                String data = sc.next();

                System.out.print("Enter divisor: ");
                String divisor = sc.next();

                int dataLen = data.length();
                int divLen = divisor.length();

                String appendedData = data;

                for (int i = 0; i < divLen - 1; i++)
                    appendedData += "0";

                char[] remainder = appendedData.toCharArray();
                char[] divisorArr = divisor.toCharArray();

                for (int i = 0; i <= dataLen - 1; i++) {
                    if (remainder[i] == '1') {
                        for (int j = 0; j < divLen; j++) {
                            remainder[i + j] =
                                (remainder[i + j] == divisorArr[j]) ? '0' : '1';
                        }
                    }
                }

                System.out.print("CRC Remainder: ");
                for (int i = dataLen; i < remainder.length; i++)
                    System.out.print(remainder[i]);

                System.out.println();
                break;

            case 3:
                sc.nextLine();
                System.out.print("Enter binary data: ");
                String parityData = sc.nextLine();

                int count = 0;

                for (int i = 0; i < parityData.length(); i++) {
                    if (parityData.charAt(i) == '1')
                        count++;
                }

                if (count % 2 == 0)
                    System.out.println("Even Parity - No Error");
                else
                    System.out.println("Odd number of 1s - Error Detected");
                break;

            default:
                System.out.println("Invalid choice");
        }
    }
}