import java.util.*;

public class quickselect {

    public static void swap(int[] arr, int i, int j) {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }

    public static int partition(int[] arr, int low, int high) {
        int pivot = arr[high];
        int i = low;

        for (int j = low; j < high; j++) {
            if (arr[j] <= pivot) {
                swap(arr, i, j);
                i++;
            }
        }

        swap(arr, i, high);
        return i;
    }

    static void quickSelect(int[] arr, int low, int high, int k) {

        if (low < high) {

            int pivotIndex = partition(arr, low, high);

            if (pivotIndex == k)
                return;

            if (pivotIndex > k)
                quickSelect(arr, low, pivotIndex - 1, k);
            else
                quickSelect(arr, pivotIndex + 1, high, k);
        }
    }

    public static void main(String[] args) {

        int[] arr = {12, 3, 5, 7, 19, 1, 4, 8};
        int k = 4;

        quickSelect(arr, 0, arr.length - 1, k - 1);

        System.out.println("Smallest " + k + " elements:");

        for (int i = 0; i < k; i++) {
            System.out.print(arr[i] + " ");
        }
    }
}