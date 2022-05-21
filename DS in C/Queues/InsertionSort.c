
#include<stdio.h>

void printArray(int arr[],int n){
    for(int i = 0;i<n;i++){
        printf("%d ",arr[i]);
    }
}

void InsertionSort(int arr[],int n){
    int key,j;
    for (int i = 1; i <=n-1; i++)    //We assume that arr[0] is already sorted hence loop started from 1
    {
        key = arr[i];   //Stores key 
        j = i- 1;       //element before key for comparison

        while(j>=0 && arr[j]>key){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}
int main(){
    int arr[] = {54,34,56,32,65,45,76,33,24};

    int n = sizeof(arr)/sizeof(arr[0]);
    printf("Before Sorting :");
    printArray(arr,n);

    InsertionSort(arr, n);    //T.C =  Worst Case : O(n2)   And Best Case : O(n)
    printf("\n");
    printf("After Sorting :");
    printArray(arr,n);

    return 0;
}