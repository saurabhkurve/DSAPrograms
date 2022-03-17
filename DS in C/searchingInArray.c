#include<stdio.h>
/*
    ! Use Linear search if array is not sorted and its time complexity is O(n)
    ! Use Binary search if array is sorted and its time complexity is O(log n)
*/

int LinearSearch(int arr[],int size,int element){
    for (int i = 0; i < size; i++)
    {
        if (arr[i]== element){
            return i;
        }
    }
    return -1;
}

int BinarySearch(int arr[],int size,int element){
    int low,mid,high;

    low = 0;
    high = size - 1;

    while(low<=high){
        mid = (low+mid)/2;
        if(arr[mid] == element){    // element found
            return mid;
        }
        else if (arr[mid] < element){   //if mid is less than element then increase low by 1
            low = mid +1;
        }else{
            high = mid -1;  //if mid is greater than element then decrease mid by 1
        }
    }
    return -1;  //if element not present in array
}

int main()
{
    int arr[] = {4,5,7,6,54,3,46,54,35,45};
    int size = sizeof(arr)/sizeof(arr[0]);
    int element = 46;
    //int index = LinearSearch(arr,size,element); // ? Linear Search in an array
    int index = BinarySearch(arr,size,element);
    printf("Element is at index %d\n",index);
    return 0;
}