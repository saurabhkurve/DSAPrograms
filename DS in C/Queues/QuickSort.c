#include <stdio.h>

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int partition(int A[], int low, int high)
{
    int pivot = A[low];
    int i = low + 1;
    int j = high;
    int temp;

    do
    {
        while (A[i] <= pivot)
        { // if i is less than pivot then increase i because we want larger element that pivot.
            i++;
        }

        while (A[j] > pivot)
        { // if j is greater than pivot then decrease j because we want smaller or equal element that pivot.
            j--;
        }

        // swap A[i] and A[j]
        if (i <j)
        {
            temp = A[i];
            A[i] = A[j];
            A[j] = temp;
        }
    } while (i < j);

    // swap A[low] i.e pivot element And a[j]
    temp = A[low];
    A[low] = A[j];
    A[j] = temp;

    return j;
}

void Quicksort(int A[], int low, int high)
{
    int partitionIndex;
    if (low < high)   //minimum 1 element required
    {
        partitionIndex = partition(A, low, high);
        Quicksort(A, low, partitionIndex - 1);  // Sort left subarray
        Quicksort(A, partitionIndex + 1, high); // Sort right subarray
    }
}

int main()
{
    int A[] = {4,2,8,7,9,5,6};
    int n = sizeof(A) / sizeof(A[0]);

    printArray(A, n);

    Quicksort(A, 0, n - 1);

    printArray(A, n);

    return 0;
}                                     