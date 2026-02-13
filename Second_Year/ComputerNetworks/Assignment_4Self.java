import java.util.Scanner;

public class Assignment_4Self {

    static Scanner sc = new Scanner(System.in);

    public static void main(String[] args) throws Exception {

        while (true) {
            System.out.println("\n===== Assignment 4 =====");
            System.out.println("1. Parity Check");
            System.out.println("2. Checksum");
            System.out.println("3. CRC");
            System.out.println("4. Exit");
            System.out.print("Enter choice: ");

            int choice = sc.nextInt();

            switch (choice) {
                case 1:
                    parityMethod();
                    break;
                case 2:
                    checksumMethod();
                    break;
                case 3:
                    crcMethod();
                    break;
                case 4:
                    System.exit(0);
            }
        }
    }

    // ================= DELAY FUNCTION =================
    static void delay() throws Exception {
        Thread.sleep(500);
    }

    static void animate(String text) throws Exception {
        for (int i = 1; i <= 3; i++) {
            System.out.print("\r" + text);
            for (int j = 0; j < i; j++)
                System.out.print(".");
            delay();
        }
        System.out.println();
    }

    // ================= PARITY =================
    static void parityMethod() throws Exception {

        System.out.print("\nSender - Enter binary data: ");
        String data = sc.next();

        delay();
        System.out.println("Counting number of 1s...");
        delay();

        int count = 0;
        for (int i = 0; i < data.length(); i++) {
            System.out.println("Reading bit: " + data.charAt(i));
            if (data.charAt(i) == '1')
                count++;
            delay();
        }

        System.out.println("Total number of 1s: " + count);
        delay();

        char parityBit = (count % 2 == 0) ? '0' : '1';

        System.out.println("Parity bit generated: " + parityBit);
        delay();

        String transmitted = data + parityBit;

        animate("Sending packet");
        System.out.println("Transmitted Data: " + transmitted);
        delay();

        System.out.print("Introduce error? (y/n): ");
        char errorChoice = sc.next().charAt(0);

        if (errorChoice == 'y') {
            transmitted = flipBit(transmitted);
        }

        animate("Receiving packet");
        System.out.println("Receiver Data: " + transmitted);
        delay();

        System.out.println("\nReceiver is verifying parity...");
        delay();

        int receiverCount = 0;

        for (int i = 0; i < transmitted.length(); i++) {
            System.out.println("Checking bit: " + transmitted.charAt(i));
            if (transmitted.charAt(i) == '1') {
                receiverCount++;
                System.out.println("Number of 1s so far: " + receiverCount);
            }
            delay();
        }

        System.out.println("Total number of 1s at receiver: " + receiverCount);
        delay();

        System.out.println("Checking if total 1s is EVEN...");
        delay();

        if (receiverCount % 2 == 0) {
            System.out.println("Parity condition satisfied.");
            delay();
            System.out.println("Packet Sent Successfully (No Error)");
        } else {
            System.out.println("Parity condition FAILED.");
            delay();
            System.out.println("Error Detected in Packet");
        }
    }

    // ================= CHECKSUM =================
    static void checksumMethod() throws Exception {

        System.out.print("\nSender - Enter first binary number: ");
        String a = sc.next();

        System.out.print("Sender - Enter second binary number: ");
        String b = sc.next();

        delay();
        System.out.println("Adding binary numbers...");
        delay();

        int sum = Integer.parseInt(a, 2) + Integer.parseInt(b, 2);
        String binarySum = Integer.toBinaryString(sum);

        System.out.println("Binary Sum: " + binarySum);
        delay();

        System.out.println("Taking 1's complement...");
        delay();

        String checksum = "";
        for (char c : binarySum.toCharArray()) {
            checksum += (c == '1') ? '0' : '1';
            delay();
        }

        System.out.println("Generated Checksum: " + checksum);
        delay();

        animate("Sending packet");
        String transmitted = binarySum;

        System.out.print("Introduce error? (y/n): ");
        char errorChoice = sc.next().charAt(0);

        if (errorChoice == 'y')
            transmitted = flipBit(binarySum);

        animate("Receiving packet");
        delay();

        System.out.println("Receiver adding received data and checksum...");
        delay();

        System.out.println("Received Data: " + transmitted);
        System.out.println("Received Checksum: " + checksum);
        delay();

        int total = Integer.parseInt(transmitted, 2) + Integer.parseInt(checksum, 2);

        System.out.println("Binary Addition Result: " + Integer.toBinaryString(total));
        delay();

        String result = Integer.toBinaryString(total);

        System.out.println("Checking if result contains only 1s...");
        delay();

        boolean valid = true;

        for (int i = 0; i < result.length(); i++) {
            System.out.println("Checking bit: " + result.charAt(i));
            if (result.charAt(i) != '1') {
                valid = false;
            }
            delay();
        }

        if (valid) {
            System.out.println("All bits are 1.");
            delay();
            System.out.println("Packet Sent Successfully (No Error)");
        } else {
            System.out.println("Not all bits are 1.");
            delay();
            System.out.println("Error Detected in Packet");
        }
    }

    // ================= CRC =================
    static void crcMethod() throws Exception {

        System.out.print("\nSender - Enter data: ");
        String data = sc.next();

        System.out.print("Sender - Enter divisor: ");
        String divisor = sc.next();

        delay();
        System.out.println("Appending zeros...");
        delay();

        String appendedData = data;
        for (int i = 0; i < divisor.length() - 1; i++)
            appendedData += "0";

        System.out.println("Appended Data: " + appendedData);
        delay();

        char[] remainder = appendedData.toCharArray();
        char[] divisorArr = divisor.toCharArray();

        System.out.println("\nPerforming Modulo-2 Division Step-by-Step:");
        delay();

        for (int i = 0; i <= data.length() - 1; i++) {
            if (remainder[i] == '1') {
                System.out.println("Dividing at position " + i);
                delay();
                for (int j = 0; j < divisor.length(); j++) {
                    remainder[i + j] =
                            (remainder[i + j] == divisorArr[j]) ? '0' : '1';
                }
                System.out.println("Current Remainder: " + new String(remainder));
                delay();
            }
        }

        String crc = "";
        for (int i = data.length(); i < remainder.length; i++)
            crc += remainder[i];

        System.out.println("CRC Generated: " + crc);
        delay();

        String transmitted = data + crc;

        animate("Sending packet");
        System.out.println("Transmitted Data: " + transmitted);

        System.out.print("Introduce error? (y/n): ");
        char errorChoice = sc.next().charAt(0);

        if (errorChoice == 'y')
            transmitted = flipBit(transmitted);

        animate("Receiving packet");
        System.out.println("Receiver Data: " + transmitted);
        delay();

        System.out.println("\nReceiver performing Modulo-2 Division Step-by-Step:");
        delay();

        char[] check = transmitted.toCharArray();
        char[] divisorArrReceiver = divisor.toCharArray();

        System.out.println("Initial Received Data: " + new String(check));
        delay();

        for (int i = 0; i <= transmitted.length() - divisor.length(); i++) {

            System.out.println("\n----------------------------------");
            System.out.println("Checking bit position " + i);
            delay();

            if (check[i] == '1') {

                System.out.println("Bit is 1 → Performing XOR with Divisor");
                delay();

                for (int j = 0; j < divisor.length(); j++) {

                    System.out.println(
                        "XOR Step: " + check[i + j] + " ⊕ " + divisorArrReceiver[j]
                    );
                    delay();

                    check[i + j] =
                        (check[i + j] == divisorArrReceiver[j]) ? '0' : '1';

                    System.out.println(
                        "Result stored at position " + (i + j) + " → " + check[i + j]
                    );
                    delay();
                }

                System.out.println("Remainder After This Step: " + new String(check));
                delay();

            } else {
                System.out.println("Bit is 0 → Skipping XOR");
                delay();
            }
        }

        System.out.println("\n==================================");
        System.out.println("Division Completed.");
        delay();

        System.out.println("\nChecking Final Remainder Bits...");
        delay();

        boolean error = false;

        int start = transmitted.length() - (divisor.length() - 1);

        System.out.println("Remainder bits start from position: " + start);
        delay();

        for (int i = start; i < transmitted.length(); i++) {

            System.out.println("Checking remainder bit at position " + i + " → " + check[i]);
            delay();

            if (check[i] != '0') {
                error = true;
            }
        }

        System.out.println("\nFinal Remainder: ");
        for (int i = start; i < transmitted.length(); i++) {
            System.out.print(check[i]);
        }
        System.out.println();
        delay();

        if (!error) {
            System.out.println("All remainder bits are ZERO.");
            delay();
            System.out.println("Therefore → Packet Sent Successfully (No Error)");
        } else {
            System.out.println("Non-zero remainder detected.");
            delay();
            System.out.println("Therefore → Error Detected in Packet");
        }
    }

    // ================= FLIP BIT =================
    static String flipBit(String data) {
        char[] arr = data.toCharArray();
        System.out.print("Enter position to flip (0 to " + (arr.length - 1) + "): ");
        int pos = sc.nextInt();
        arr[pos] = (arr[pos] == '1') ? '0' : '1';
        return new String(arr);
    }
}