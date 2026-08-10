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

    int[] randomSortedArray = {1, 5, 6, 2, 1, 3, 5, 6};
    int[] ascendingSorted = {1, 2, 3, 4, 5};
    int[] descendingSorted = {5, 4, 3, 2, 1};

    heapSort(randomSortedArray);
    heapSort(ascendingSorted);
    heapSort(descendingSorted);

    // Random array
    System.out.println("Random Sorted Array:");

    for (int i = 0; i < randomSortedArray.length; i++) {
        System.out.print(randomSortedArray[i] + " ");
    }

    // Ascending input
    System.out.println("\nAscending Sorted answer:");

    for (int i = 0; i < ascendingSorted.length; i++) {
        System.out.print(ascendingSorted[i] + " ");
    }

    // Descending input
    System.out.println("\nDescending Sorted answer:");

    for (int i = 0; i < descendingSorted.length; i++) {
        System.out.print(descendingSorted[i] + " ");
    }

    System.out.println();
}
}