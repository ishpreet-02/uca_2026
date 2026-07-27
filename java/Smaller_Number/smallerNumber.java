import java.util.*;

public class smallerNumber {

    static int[] answer;

    static void mergeSort(int[] nums, int[] indices, int left, int right) {
        if (left >= right)
            return;

        int mid = left + (right - left) / 2;

        mergeSort(nums, indices, left, mid);
        mergeSort(nums, indices, mid + 1, right);

        merge(nums, indices, left, mid, right);
    }

    static void merge(int[] nums, int[] indices, int left, int mid, int right) {

        int[] temp = new int[right - left + 1];

        int i = left;
        int j = mid + 1;
        int k = 0;

        int smallerCount = 0;

        while (i <= mid && j <= right) {

            if (nums[indices[j]] < nums[indices[i]]) {
                smallerCount++;
                temp[k++] = indices[j++];
            } 
            else {
                answer[indices[i]] += smallerCount;
                temp[k++] = indices[i++];
            }
        }

        while (i <= mid) {
            answer[indices[i]] += smallerCount;
            temp[k++] = indices[i++];
        }

        while (j <= right) {
            temp[k++] = indices[j++];
        }

        for (int x = 0; x < temp.length; x++) {
            indices[left + x] = temp[x];
        }
    }


    public static void main(String[] args) {

        int arr[] = {5, 2, 6, 1};

        int n = arr.length;
        answer = new int[n];
        int[] indices = new int[n];
        for (int i = 0; i < n; i++) {
            indices[i] = i;
        }

        mergeSort(arr, indices, 0, n - 1);

        for (int i = 0; i < n; i++) {
            System.out.print(answer[i] + " ");
        }
    }
}