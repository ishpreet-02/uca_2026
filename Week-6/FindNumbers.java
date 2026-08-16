import java.util.*;

public class FindNumbers {

    private static int findNumbers(int[] arr) {
        int[] bit = new int[32];

        for (int num : arr) {
            for (int i = 0; i < 32; i++) {
                if ((num & (1 << i)) != 0) {
                    bit[i]++;
                }
            }
        }

        int answer = 0;

        for (int i = 0; i < 32; i++) {
            if (bit[i] % 3 != 0) {
                answer |= (1 << i);
            }
        }

        return answer;
    }

    public static void main(String[] args) {
        int[] arr = {1, 2, 3, 4, 1, 2, 4, 1, 2, 3, 4, 3, 3};
        int[] arr2 = {5, 6, 7, 5, 6, 7, 5, 6, 7, 9, 9, 9, 9};

        System.out.println(findNumbers(arr));
        System.out.println(findNumbers(arr2));
    }
}