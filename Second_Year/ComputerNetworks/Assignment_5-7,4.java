import java.util.Scanner;

class Hamming74 {

    // Encode 4-bit data into 7-bit Hamming code
    public static int[] encode(int[] dataBits) {
        int[] hamming = new int[7];

        // Place data bits in positions 3,5,6,7
        hamming[2] = dataBits[0]; // D1
        hamming[4] = dataBits[1]; // D2
        hamming[5] = dataBits[2]; // D3
        hamming[6] = dataBits[3]; // D4

        // Calculate parity bits
        hamming[0] = hamming[2] ^ hamming[4] ^ hamming[6]; // P1
        hamming[1] = hamming[2] ^ hamming[5] ^ hamming[6]; // P2
        hamming[3] = hamming[4] ^ hamming[5] ^ hamming[6]; // P4

        return hamming;
    }

    // Introduce a single-bit error at given position (1-based)
    public static void introduceError(int[] hamming, int pos) {
        if(pos < 1 || pos > 7) {
            System.out.println("Invalid position! No error introduced.");
            return;
        }
        hamming[pos-1] ^= 1;
        System.out.println("Error introduced at position: " + pos);
    }

    // Decode and correct Hamming code
    public static int[] decode(int[] received) {
        int S1 = received[0] ^ received[2] ^ received[4] ^ received[6];
        int S2 = received[1] ^ received[2] ^ received[5] ^ received[6];
        int S4 = received[3] ^ received[4] ^ received[5] ^ received[6];

        int errorPosition = S4*4 + S2*2 + S1*1;

        if(errorPosition != 0) {
            System.out.println("Error detected at position: " + errorPosition);
            received[errorPosition-1] ^= 1; // correct the bit
            System.out.println("Error corrected!");
        } else {
            System.out.println("No error detected.");
        }

        return received;
    }

    // Print bit array
    public static void printBits(String label, int[] bits) {
        System.out.print(label + ": ");
        for(int b : bits) System.out.print(b);
        System.out.println();
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int[] dataBits = new int[4];

        System.out.println("Enter 4 data bits (0 or 1) separated by space:");
        for(int i=0;i<4;i++){
            dataBits[i]=sc.nextInt();
            if(dataBits[i]!=0 && dataBits[i]!=1){System.out.println("Enter 0 or 1 only"); i--;}
        }

        // Encode
        int[] hamming = encode(dataBits);
        printBits("Transmitted Hamming Code", hamming);

        // Introduce error
        System.out.println("Enter position to introduce error (1-7), 0 for no error:");
        int pos = sc.nextInt();
        if(pos!=0) introduceError(hamming,pos);

        printBits("Received Hamming Code", hamming);

        // Decode
        int[] corrected = decode(hamming);
        printBits("Corrected Hamming Code", corrected);

        // Extract original data
        int[] original = new int[4];
        original[0]=corrected[2];
        original[1]=corrected[4];
        original[2]=corrected[5];
        original[3]=corrected[6];

        printBits("Original Data Extracted", original);
        sc.close();
    }
}