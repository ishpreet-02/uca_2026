#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    int id;
    char name[50];
    float marks;
} Student;


// Generic swap function
void swap(void *a, void *b, size_t size)
{
    void *temp = malloc(size);

    memcpy(temp, a, size);
    memcpy(a, b, size);
    memcpy(b, temp, size);

    free(temp);
}


// Heapify function
void heapify(void *arr, int n, int i, size_t size,
             int (*compare)(const void *, const void *))
{
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    int largest = i;

    if (left < n &&
        compare((char *)arr + left * size,
                (char *)arr + largest * size) > 0)
    {
        largest = left;
    }

    if (right < n &&
        compare((char *)arr + right * size,
                (char *)arr + largest * size) > 0)
    {
        largest = right;
    }


    if (largest != i)
    {
        swap((char *)arr + i * size,
             (char *)arr + largest * size,
             size);

        heapify(arr, n, largest, size, compare);
    }
}


// Generic Heap Sort
void heapSort(void *arr, int n, size_t size,
              int (*compare)(const void *, const void *))
{
    // Build max heap
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        heapify(arr, n, i, size, compare);
    }


    // Extract elements from heap
    for (int i = n - 1; i > 0; i--)
    {
        swap(arr, (char *)arr + i * size, size);

        heapify(arr, i, 0, size, compare);
    }
}


// Integer comparator
int compareInt(const void *a, const void *b)
{
    int x = *(int *)a;
    int y = *(int *)b;

    if (x > y)
        return 1;
    else if (x < y)
        return -1;

    return 0;
}


// Float comparator
int compareFloat(const void *a, const void *b)
{
    float x = *(float *)a;
    float y = *(float *)b;

    if (x > y)
        return 1;
    else if (x < y)
        return -1;

    return 0;
}


// Double comparator
int compareDouble(const void *a, const void *b)
{
    double x = *(double *)a;
    double y = *(double *)b;

    if (x > y)
        return 1;
    else if (x < y)
        return -1;

    return 0;
}


// Structure comparator (sort by marks)
int compareStudent(const void *a, const void *b)
{
    Student *x = (Student *)a;
    Student *y = (Student *)b;

    if (x->marks > y->marks)
        return 1;
    else if (x->marks < y->marks)
        return -1;

    return 0;
}


int main()
{
    int intArr[] = {56, 12, 89, 3, 45, 21};

    float floatArr[] = {7.8, 2.3, 15.6, 4.1, 9.9};

    double doubleArr[] = {78.45, 12.34, 56.78, 3.21, 90.12};

    Student students[] =
    {
        {5, "Arjun", 76.5},
        {2, "Neha", 88.0},
        {8, "Vikas", 69.5},
        {1, "Priya", 95.5},
        {4, "Rohan", 82.0}
    };


    int n1 = sizeof(intArr) / sizeof(intArr[0]);
    int n2 = sizeof(floatArr) / sizeof(floatArr[0]);
    int n3 = sizeof(doubleArr) / sizeof(doubleArr[0]);
    int n4 = sizeof(students) / sizeof(students[0]);


    // Sort integer array
    heapSort(intArr, n1, sizeof(int), compareInt);

    printf("Sorted Integers:\n");
    for(int i = 0; i < n1; i++)
        printf("%d ", intArr[i]);

    printf("\n\n");


    // Sort float array
    heapSort(floatArr, n2, sizeof(float), compareFloat);

    printf("Sorted Floats:\n");
    for(int i = 0; i < n2; i++)
        printf("%.2f ", floatArr[i]);

    printf("\n\n");


    // Sort double array
    heapSort(doubleArr, n3, sizeof(double), compareDouble);

    printf("Sorted Doubles:\n");
    for(int i = 0; i < n3; i++)
        printf("%.2lf ", doubleArr[i]);

    printf("\n\n");


    // Sort structure array
    heapSort(students, n4, sizeof(Student), compareStudent);

    printf("Sorted Students by Marks:\n");

    for(int i = 0; i < n4; i++)
    {
        printf("%d %s %.2f\n",
               students[i].id,
               students[i].name,
               students[i].marks);
    }


    return 0;
}