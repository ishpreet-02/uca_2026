#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_ALGORITHMS 6
#define NUM_INPUT_TYPES 3
#define NUM_SIZES 9

typedef void (*SortFunction)(int arr[], int n);

typedef struct {
    const char *name;
    SortFunction sort;
} Algorithm;

typedef struct {
    const char *name;
    void (*generate)(int arr[], int n);
} InputType;

void bubbleSort(int arr[], int n);
void insertionSort(int arr[], int n);
void selectionSort(int arr[], int n);
void quickSort(int arr[], int low, int high);
void mergeSort(int arr[], int left, int right);
void heapSort(int arr[], int n);

void generateRandom(int arr[], int n);
void generateAscending(int arr[], int n);
void generateDescending(int arr[], int n);

void copyArray(int destination[], const int source[], int n);
void swap(int *a, int *b);
int partition(int arr[], int low, int high);
void heapify(int arr[], int n, int root);
void merge(int arr[], int left, int middle, int right);

static void quickSortWrapper(int arr[], int n);
static void mergeSortWrapper(int arr[], int n);
static double measureSortTime(SortFunction sort, int arr[], int n);
static int isSorted(const int arr[], int n);
static int *allocateArray(int n);
static void freeArray(int *arr);

static size_t activeAllocations = 0;

int main(void)
{
    const int sizes[NUM_SIZES] = {0, 8000, 12000, 16000, 20000, 24000, 28000, 32000, 36000};
    const Algorithm algorithms[NUM_ALGORITHMS] = {
        {"Bubble", bubbleSort},
        {"Insertion", insertionSort},
        {"Selection", selectionSort},
        {"Quick", quickSortWrapper},
        {"Merge", mergeSortWrapper},
        {"Heap", heapSort}
    };
    const InputType inputTypes[NUM_INPUT_TYPES] = {
        {"Random", generateRandom},
        {"Ascending", generateAscending},
        {"Descending", generateDescending}
    };

    srand((unsigned int)time(NULL));

    printf("Algorithm,InputType,Size,ExecutionTime(ms)\n");

    for (int sizeIndex = 0; sizeIndex < NUM_SIZES; sizeIndex++) {
        int n = sizes[sizeIndex];
        int *working = allocateArray(n);
        int *originals[NUM_INPUT_TYPES];

        for (int inputIndex = 0; inputIndex < NUM_INPUT_TYPES; inputIndex++) {
            originals[inputIndex] = allocateArray(n);
            inputTypes[inputIndex].generate(originals[inputIndex], n);
        }

        for (int algorithmIndex = 0; algorithmIndex < NUM_ALGORITHMS; algorithmIndex++) {
            for (int inputIndex = 0; inputIndex < NUM_INPUT_TYPES; inputIndex++) {
                copyArray(working, originals[inputIndex], n);

                double elapsed = measureSortTime(algorithms[algorithmIndex].sort, working, n);

                if (!isSorted(working, n)) {
                    fprintf(stderr, "Error: %s sort failed for %s input of size %d.\n",
                            algorithms[algorithmIndex].name, inputTypes[inputIndex].name, n);
                    freeArray(working);
                    for (int cleanupIndex = 0; cleanupIndex < NUM_INPUT_TYPES; cleanupIndex++) {
                        freeArray(originals[cleanupIndex]);
                    }
                    return EXIT_FAILURE;
                }

                printf("%s,%s,%d,%.2f\n",
                       algorithms[algorithmIndex].name,
                       inputTypes[inputIndex].name,
                       n,
                       elapsed);
            }
        }

        freeArray(working);
        for (int inputIndex = 0; inputIndex < NUM_INPUT_TYPES; inputIndex++) {
            freeArray(originals[inputIndex]);
        }
    }

    if (activeAllocations != 0) {
        fprintf(stderr, "Error: %lu memory allocation(s) were not freed.\n",
                (unsigned long)activeAllocations);
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}

void bubbleSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++) {
        int swapped = 0;

        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);
                swapped = 1;
            }
        }

        if (!swapped) {
            break;
        }
    }
}

void insertionSort(int arr[], int n)
{
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = key;
    }
}

void selectionSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;

        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }

        if (minIndex != i) {
            swap(&arr[i], &arr[minIndex]);
        }
    }
}

void quickSort(int arr[], int low, int high)
{
    while (low < high) {
        int pivotIndex = partition(arr, low, high);

        /* Recurse into the smaller side first to keep stack usage bounded. */
        if (pivotIndex - low < high - pivotIndex) {
            quickSort(arr, low, pivotIndex - 1);
            low = pivotIndex + 1;
        } else {
            quickSort(arr, pivotIndex + 1, high);
            high = pivotIndex - 1;
        }
    }
}

void mergeSort(int arr[], int left, int right)
{
    if (left < right) {
        int middle = left + (right - left) / 2;

        mergeSort(arr, left, middle);
        mergeSort(arr, middle + 1, right);
        merge(arr, left, middle, right);
    }
}

void heapSort(int arr[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }

    for (int i = n - 1; i > 0; i--) {
        swap(&arr[0], &arr[i]);
        heapify(arr, i, 0);
    }
}

void generateRandom(int arr[], int n)
{
    for (int i = 0; i < n; i++) {
        arr[i] = rand();
    }
}

void generateAscending(int arr[], int n)
{
    for (int i = 0; i < n; i++) {
        arr[i] = i;
    }
}

void generateDescending(int arr[], int n)
{
    for (int i = 0; i < n; i++) {
        arr[i] = n - i;
    }
}

void copyArray(int destination[], const int source[], int n)
{
    for (int i = 0; i < n; i++) {
        destination[i] = source[i];
    }
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int low, int high)
{
    int middle = low + (high - low) / 2;
    int pivot = arr[middle];

    swap(&arr[middle], &arr[high]);

    int storeIndex = low;
    for (int i = low; i < high; i++) {
        if (arr[i] < pivot) {
            swap(&arr[i], &arr[storeIndex]);
            storeIndex++;
        }
    }

    swap(&arr[storeIndex], &arr[high]);
    return storeIndex;
}

void heapify(int arr[], int n, int root)
{
    int largest = root;
    int leftChild = 2 * root + 1;
    int rightChild = 2 * root + 2;

    if (leftChild < n && arr[leftChild] > arr[largest]) {
        largest = leftChild;
    }

    if (rightChild < n && arr[rightChild] > arr[largest]) {
        largest = rightChild;
    }

    if (largest != root) {
        swap(&arr[root], &arr[largest]);
        heapify(arr, n, largest);
    }
}

void merge(int arr[], int left, int middle, int right)
{
    int leftSize = middle - left + 1;
    int rightSize = right - middle;
    int *leftArray = allocateArray(leftSize);
    int *rightArray = allocateArray(rightSize);

    for (int i = 0; i < leftSize; i++) {
        leftArray[i] = arr[left + i];
    }

    for (int i = 0; i < rightSize; i++) {
        rightArray[i] = arr[middle + 1 + i];
    }

    int i = 0;
    int j = 0;
    int k = left;

    while (i < leftSize && j < rightSize) {
        if (leftArray[i] <= rightArray[j]) {
            arr[k] = leftArray[i];
            i++;
        } else {
            arr[k] = rightArray[j];
            j++;
        }
        k++;
    }

    while (i < leftSize) {
        arr[k] = leftArray[i];
        i++;
        k++;
    }

    while (j < rightSize) {
        arr[k] = rightArray[j];
        j++;
        k++;
    }

    freeArray(leftArray);
    freeArray(rightArray);
}

static void quickSortWrapper(int arr[], int n)
{
    quickSort(arr, 0, n - 1);
}

static void mergeSortWrapper(int arr[], int n)
{
    mergeSort(arr, 0, n - 1);
}

static double measureSortTime(SortFunction sort, int arr[], int n)
{
    clock_t start;
    clock_t end;

    start = clock();
    sort(arr, n);
    end = clock();

    return ((double)(end - start)) * 1000.0 / CLOCKS_PER_SEC;
}

static int isSorted(const int arr[], int n)
{
    for (int i = 1; i < n; i++) {
        if (arr[i - 1] > arr[i]) {
            return 0;
        }
    }

    return 1;
}

static int *allocateArray(int n)
{
    if (n == 0) {
        return NULL;
    }

    int *arr = malloc((size_t)n * sizeof(int));

    if (arr == NULL) {
        fprintf(stderr, "Error: Memory allocation failed for %d integers.\n", n);
        exit(EXIT_FAILURE);
    }

    activeAllocations++;

    return arr;
}

static void freeArray(int *arr)
{
    if (arr != NULL) {
        free(arr);
        activeAllocations--;
    }
}
