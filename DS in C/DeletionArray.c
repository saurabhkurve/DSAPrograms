#include<stdio.h>
void display(int arr[],int n){
    // Traversal of an array
    for (int i = 0; i < n; i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
}
void deletion(int arr[],int size,int index){
   
    
    for (int i = index; i < size; i++)
    {
        arr[i]=arr[i+1];
    }
}
int main(){
    int arr[100] = { 2,5,7,9,67,54,56};
    int size = 7 , index = 5 ;
    display(arr,size);
    deletion(arr,size,index);
    size -= 1;
    display(arr,size);
    return 0;
}