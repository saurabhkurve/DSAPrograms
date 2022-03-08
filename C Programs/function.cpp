#include<iostream>
#include<string>
using namespace std;
void myfunction(string ,int);
int main(){
    myfunction("Saurabh",23);
    return 0;
}
void myfunction(string name ,int age){
    cout<<"My name is "<< name << " and age is " <<age<<endl;
}