#include<stdio.h>
int main(){
    int s[4][2]={
        {1234,56},
        {1212,33},
        {1414,80},
        {1312,78},
    };

    for(int i = 0; i <=3; i++){
        for (int j = 0; j <=3; j++)
        {
            printf("address of %d th 1-D array = %u\n",i,s[i][j]);
        }
          
    }
   
    
}