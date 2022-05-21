#include <stdio.h>

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void BubbleSort(int arr[], int n)      //Non-Adaptive T.C = O(N2)
{
    int temp;

    for (int i = 0; i < n - 1; i++)    // For number of passes
    { 
        // printf("Number of passes is %d\n", i + 1);
        for (int j = 0; j < n - 1 - i; j++)     // For comparison in each pass
        { 
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}


//We can apply this bubbile sort if array is sorted
void BubbleSort1(int arr[], int n)      //We made it Adaptive T.C = O(N)
{
    int temp;
    int isSorted = 0;
    for (int i = 0; i < n - 1; i++)       // For number of passes
    { 
        printf("Number of passes is %d\n", i + 1);
        isSorted = 1;         //If array is already sorted it never go into second nested loop
        for (int j = 0; j < n - 1 - i; j++)      // For comparison in each pass
        { 
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                isSorted = 0;
            }
        }
        if(isSorted){
            return;
        }
    }
}

int main()
{
    int arr[] = {65, 33, 23, 78, 42, 8, 32, 71};
    // int arr[] = {1,2,3,4,5,6,7};
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("Before Sorting:\n");
    printArray(arr, n);

    BubbleSort(arr, n);
    // BubbleSort1(arr, n);

    printf("After Sorting:\n");
    printArray(arr, n);
    return 0;
}