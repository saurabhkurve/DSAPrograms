#include<stdio.h>


int Factorial(int n){
    int fact = 0;
    if(n<=1){
        return 1;
    }

        fact =  n * Factorial(n-1);   //fib(n-1)+fib(n-2) for fibbonaci series
        return fact;
}

int main(){
    int n = 5;

    int fact = Factorial(n);
    printf("Factorial is %d ",fact);
    return 0;
}