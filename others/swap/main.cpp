#include<iostream>
using namespace std;

int main(){

    // 1) swap built in
    // int a=5,b=6;
    // swap(a,b);
    // cout<<a<<b;

    // 2) temp variables
    // int a=5,b=6;
    // int temp = a;  // temp = 5
    // a=b;   // b =6 , a =6
    // b=temp;     

    // cout<<a<<b;

    // 3) arithematic method (interview-question)
    // int a=5,b=6;
    // a = a + b; // 11
    // b = a - b; // 5
    // a = a - b; // 6

    // cout<<a<<b;

    // 4) xor method
    int a=5,b=6;
    a = a^b;
    b=b^a;
    a = a^b;

    cout<<a<<b;

    return 0;
}