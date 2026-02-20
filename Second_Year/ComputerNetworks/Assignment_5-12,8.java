import java.util.Scanner;

class Assignment_5 {

    // Function to calculate parity bits for 12-bit Hamming (12,8)
    public static int[] encode(int[] dataBits) {
        int[] hamming = new int[12];

        // Place data bits in positions 3,5,6,7,9,10,11,12
        hamming[2] = dataBits[0]; // D1
        hamming[4] = dataBits[1]; // D2
        hamming[5] = dataBits[2]; // D3
        hamming[6] = dataBits[3]; // D4
        hamming[8] = dataBits[4]; // D5
        hamming[9] = dataBits[5]; // D6
        hamming[10] = dataBits[6]; // D7
        hamming[11] = dataBits[7]; // D8

        // Calculate parity bits based on positions (powers of 2)
        // P1 checks 1,3,5,7,9,11
        hamming[0] = hamming[2] ^ hamming[4] ^ hamming[6] ^ hamming[8] ^ hamming[10];
        // P2 checks 2,3,6,7,10,11
        hamming[1] = hamming[2] ^ hamming[5] ^ hamming[6] ^ hamming[9] ^ hamming[10];
        // P4 checks 4,5,6,7,12
        hamming[3] = hamming[4] ^ hamming[5] ^ hamming[6] ^ hamming[11];
        // P8 checks 8,9,10,11,12
        hamming[7] = hamming[8] ^ hamming[9] ^ hamming[10] ^ hamming[11];

        return hamming;
    }

    // Function to introduce an error at given position (1-based)
    public static void introduceError(int[] hamming, int pos) {
        if(pos < 1 || pos > 12) {
            System.out.println("Invalid position! No error introduced.");
            return;
        }
        hamming[pos-1] ^= 1; // flip the bit
        System.out.println("Error introduced at position: " + pos);
    }

    // Function to detect and correct single-bit error
    public static int[] decode(int[] received) {
        // Recalculate syndrome bits
        int S1 = received[0] ^ received[2] ^ received[4] ^ received[6] ^ received[8] ^ received[10];
        int S2 = received[1] ^ received[2] ^ received[5] ^ received[6] ^ received[9] ^ received[10];
        int S4 = received[3] ^ received[4] ^ received[5] ^ received[6] ^ received[11];
        int S8 = received[7] ^ received[8] ^ received[9] ^ received[10] ^ received[11];

        int errorPosition = S8*8 + S4*4 + S2*2 + S1*1;

        if(errorPosition != 0) {
            System.out.println("Error detected at position: " + errorPosition);
            received[errorPosition-1] ^= 1; // Correct the bit
            System.out.println("Error corrected!");
        } else {
            System.out.println("No error detected.");
        }

        return received;
    }

    // Function to print bit array nicely
    public static void printBits(String label, int[] bits) {
        System.out.print(label + ": ");
        for(int b : bits) {
            System.out.print(b);
        }
        System.out.println();
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int[] dataBits = new int[8];

        System.out.println("Enter 8 data bits (0 or 1) separated by space:");
        for(int i=0; i<8; i++) {
            dataBits[i] = sc.nextInt();
            if(dataBits[i] != 0 && dataBits[i] != 1) {
                System.out.println("Invalid input! Enter only 0 or 1.");
                i--;
            }
        }

        // Sender side: encode
        int[] hamming = encode(dataBits);
        printBits("Transmitted Hamming Code", hamming);

        // Optional: introduce an error
        System.out.println("Enter position to introduce error (1-12), 0 for no error:");
        int errorPos = sc.nextInt();
        if(errorPos != 0) {
            introduceError(hamming, errorPos);
        }

        printBits("Received Hamming Code", hamming);

        // Receiver side: detect and correct
        int[] corrected = decode(hamming);
        printBits("Corrected Hamming Code", corrected);

        // Extract original data
        int[] originalData = new int[8];
        originalData[0] = corrected[2];
        originalData[1] = corrected[4];
        originalData[2] = corrected[5];
        originalData[3] = corrected[6];
        originalData[4] = corrected[8];
        originalData[5] = corrected[9];
        originalData[6] = corrected[10];
        originalData[7] = corrected[11];

        printBits("Original Data Extracted", originalData);

        sc.close();
    }
}