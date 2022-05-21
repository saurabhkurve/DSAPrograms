#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int maximun(int A[], int n)
{
    int max = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        if (max < A[i])
        {
            max = A[i];
        }
    }
    return max;
}

void countSort(int A[], int n)
{
    int i, j;

    // Find the maximum element in A
    int max = maximun(A, n);

    // Create the count array
    int *count = (int *)malloc((max + 1) * sizeof(int));

    // Initialize the array elements to 0
    for (i = 0; i < max + 1; i++)
    {
        count[i] = 0;
    }

    // Increment the corresponding index in the count array
    for (i = 0; i < n; i++)
    {
        count[A[i]] = count[A[i]] + 1;
    }

    i = 0;  //counter for count array
    j = 0;  //counter for given array A


    while(i <= max){  // i < max+1
        if(count[i]>0){
            A[j] = i;
            count[i] = count[i] - 1;
            j++;
        }
        else{
            i++;
        }
    }
}

int main()
{

    int A[] = {4, 2, 8, 7, 9, 5, 6};
    int n = sizeof(A) / sizeof(A[0]);

    printf("Before Count Sort : \n");
    printArray(A, n);

    countSort(A, n);

    printf("After Count Sort : \n");
    printArray(A, n);

    return 0;
}