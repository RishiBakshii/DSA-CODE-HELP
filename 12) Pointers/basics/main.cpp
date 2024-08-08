/*
What is a Pointer?
=> It is just a variable that stores the address of another variable

int a =5;
cout<<&5  # this will print the address of a
*/

#include<iostream>
using namespace std;

int main(){
    

    int a=5;
    int b=a;

    int* c = &a;

    /* 

    *int = pointer to an integer 
    &a = returns the address of a

    */


    cout<<c;

    return 0;
}