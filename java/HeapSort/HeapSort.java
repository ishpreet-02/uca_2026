import java.util.Scanner;

public class HeapSort {

    static void swap(int[] arr, int i, int j) {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }

    static void heapifyDown(int[] arr, int index, int size) {

        int largest = index;

        int left = 2 * index + 1;
        int right = 2 * index + 2;

        if (left < size && arr[left] > arr[largest]) {
            largest = left;
        }

        if (right < size && arr[right] > arr[largest]) {
            largest = right;
        }

        if (largest != index) {
            swap(arr, index, largest);
            heapifyDown(arr, largest, size);
        }
    }

    static void buildMaxHeap(int[] arr) {

        int n = arr.length;

        for (int i = n / 2 - 1; i >= 0; i--) {
            heapifyDown(arr, i, n);
        }
    }

    static void heapSort(int[] arr) {

        int n = arr.length;

        buildMaxHeap(arr);

        for (int size = n; size > 1; size--) {

            swap(arr, 0, size - 1);

            heapifyDown(arr, 0, size - 1);
        }
    }

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        System.out.print("Enter number of elements: ");
        int n = sc.nextInt();

        int[] arr = new int[n];

        for (int i = 0; i < n; i++) {
            arr[i] = sc.nextInt();
        }

        heapSort(arr);

        System.out.println("\nAfter sorting:");

        for (int x : arr) {
            System.out.print(x + " ");
        }

        sc.close();
    }
}