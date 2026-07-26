import java.util.*;

public class countInversions {

    static int merge(int[] arr, int low, int mid, int high) {

        int[] temp = new int[high - low + 1];

        int left = low;
        int right = mid + 1;
        int k = 0;

        int cnt = 0;

        while (left <= mid && right <= high) {

            if (arr[left] <= arr[right]) {
                temp[k++] = arr[left++];
            } 
            else {
                temp[k++] = arr[right++];

                // Count inversions
                cnt += (mid - left + 1);
            }
        }

        while (left <= mid) {
            temp[k++] = arr[left++];
        }

        while (right <= high) {
            temp[k++] = arr[right++];
        }

        for (int i = low; i <= high; i++) {
            arr[i] = temp[i - low];
        }

        return cnt;
    }


    static int mergeSort(int[] arr, int low, int high) {

        int cnt = 0;

        if (low >= high)
            return cnt;

        int mid = (low + high) / 2;

        cnt += mergeSort(arr, low, mid);
        cnt += mergeSort(arr, mid + 1, high);

        cnt += merge(arr, low, mid, high);

        return cnt;
    }


    static int numberOfInversions(int[] arr, int n) {
        return mergeSort(arr,0, n - 1);
    }


    public static void main(String[] args) {

        int[] arr = {1, 2, 4, 1, 3, 5};
        int n = arr.length;

        int cnt = numberOfInversions(arr, n);

        System.out.println("The number of inversions are: " + cnt);
    }
}