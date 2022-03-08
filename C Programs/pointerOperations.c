#include<stdio.h>
int main(int argc, char const *argv[])
{
    int arr[]={10,20,30,45,67,56,74};
    int i = 4,*j,*k,*x,*y;
    j = &i;
    j = j+ 9;
    printf("j = %ls\n",j);
    k = &i;
    k = k + 3;
    printf("k = %ls\n",k);
    x = &arr[1];
    printf("x = %ls\n",x);
    y = &arr[5];
    printf("y = %ls\n",y);
    printf("%ld\n",y-x);
    j = &arr[4];
    printf("j = %ls\n",j);
    k = (arr+ 4);
    printf("k = %ls\n",k);
    if(j==k){
        printf("The pointer pionts to the same location\n");
    } 
    else{
        printf("The two pointer points to the different location\n");
    }
    return 0;
}
