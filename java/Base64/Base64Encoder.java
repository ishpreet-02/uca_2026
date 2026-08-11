import java.util.*;

public class Base64Encoder {

    static final String TABLE =
            "ABCDEFGHIJKLMNOPQRSTUVWXYZ" +
            "abcdefghijklmnopqrstuvwxyz" +
            "0123456789+/";

    static String encode(String input) {

        StringBuilder result = new StringBuilder();

        for (int i = 0; i < input.length(); i += 3) {

            int b1 = input.charAt(i);
            int b2 = (i + 1 < input.length())
                    ? input.charAt(i + 1)
                    : 0;
            int b3 = (i + 2 < input.length())
                    ? input.charAt(i + 2)
                    : 0;

            // Convert 3 bytes into four 6-bit values
            int val1 = (b1 >> 2) & 63;
            int val2 = ((b1 & 3) << 4) | (b2 >> 4);
            int val3 = ((b2 & 15) << 2) | (b3 >> 6);
            int val4 = b3 & 63;

            // First two Base64 characters
            result.append(TABLE.charAt(val1));
            result.append(TABLE.charAt(val2));

            // Third character or padding
            if (i + 1 < input.length()) {
                result.append(TABLE.charAt(val3));
            } else {
                result.append('=');
            }

            // Fourth character or padding
            if (i + 2 < input.length()) {
                result.append(TABLE.charAt(val4));
            } else {
                result.append('=');
            }
        }

        return result.toString();
    }

    public static void main(String[] args) {

        System.out.println(encode("Man"));
        System.out.println(encode("Ma"));
        System.out.println(encode("A"));
        System.out.println(encode("Cat"));
        System.out.println(encode("Hello World"));
        System.out.println(encode(""));
    }
}