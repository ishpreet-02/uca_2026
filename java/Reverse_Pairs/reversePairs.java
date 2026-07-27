import java.util.*;

public class reversePairs {

    private static void merge(int[] nums, int low, int mid, int high) {

        ArrayList<Integer> temp = new ArrayList<>();
        int left = low;
        int right = mid + 1;

        while (left <= mid && right <= high) {
            if (nums[left] <= nums[right]) {
                temp.add(nums[left]);
                left++;
            } 
            else {
                temp.add(nums[right]);
                right++;
            }
        }

        while (left <= mid) {
            temp.add(nums[left]);
            left++;
        }

        while (right <= high) {
            temp.add(nums[right]);
            right++;
        }


        for (int i = low; i <= high; i++) {
            nums[i] = temp.get(i - low);
        }
    }


    private static long countPairs(int[] nums, int low, int mid, int high) {

        long count = 0;
        int right = mid + 1;

        for (int i = low; i <= mid; i++) {
            while (right <= high && 
                   (long) nums[i] > 2L * nums[right]) {

                right++;
            }
            count += (right - (mid + 1));
        }

        return count;
    }


    private static long mergeSort(int[] nums, int low, int high) {

        long count = 0;

        if (low >= high)
            return 0;

        int mid = low + (high - low) / 2;

        count += mergeSort(nums, low, mid);
        count += mergeSort(nums, mid + 1, high);
        count += countPairs(nums, low, mid, high);

        merge(nums, low, mid, high);

        return count;
    }


    public static long reversepairs(int[] nums) {

        return mergeSort(nums, 0, nums.length - 1);

    }


    public static void main(String[] args) {

        int[] nums = {1, 3, 2, 3, 1};
        long ans = reversepairs(nums);
        System.out.println(ans);

    }
}