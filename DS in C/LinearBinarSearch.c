#include<stdio.h>
//Linear search of array with O(n) complexity
// int LinearSearch(int arr[],int size,int element){   
//     for (int i = 0; i < size; i++)
//     {
//         if(arr[i]==element){
//             return i;
//         }
//     }
//     return -1;
// }

//Binary search for array with O(log n) complexity

int BinarySearch(int arr[],int size,int element){
    int low,high,mid;
    low = 0;
    high = size - 1;
    
    while(low <= high){
        mid = (low + high) / 2;
        if(arr[mid] == element){
            return mid;
        }
        else if(arr[mid] < element){
            low = mid + 1;
        }else{
            high = mid - 1;
        }
    }
    return -1;
}


int main(){
    //Linear search for Unsorted array
    // int arr [] = {4,56,34,75,765,456,335,387};
    // int size = sizeof(arr)/sizeof(arr[0]);
    // int element = 73;
    // int searched_index = LinearSearch(arr,size,element);

    //Binary Search for sorted array
    int arr [] = {4,55,78,89,98,123,345,367,777};
    int size = sizeof(arr)/sizeof(arr[0]);
    int element = 78;
    int searched_index = BinarySearch(arr,size,element);
    printf("Element %d is found at %d index\n",element,searched_index);
    return 0;
}