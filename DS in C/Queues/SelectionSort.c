#include<stdio.h>


void printArray(int arr[],int n){
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
}

void SelectionSort(int arr[],int n){
    int minIndex,temp;  //t.c = O(n2)
    for(int i=0;i<n-1;i++){    //if we sort n-1 elements then last element will sort automatically i.e. It will place at right place
        minIndex = i;
        // printf("Number of passes %d\n",i);
        for(int j=i+1;j<=n-1;j++){  // Or j<n
            if(arr[j]<arr[minIndex]){
                minIndex = j;
            }
        }
        temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
    }
}




int main(){
    int arr[] = {65,34,56,77,54,54,98,62,12,60};

    int size = sizeof(arr)/sizeof(arr[0]);
    printf("Before Sorting: ");
    printArray(arr,size);
    printf("\n");

    SelectionSort(arr,size);

    printf("After Sorting: ");
    printArray(arr,size);   

    printf("\n");
    return 0;
}