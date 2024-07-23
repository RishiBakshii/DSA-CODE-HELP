#include<iostream>
using namespace std;

int main(){
    int age;

    cout<<"Enter your age value";
    cin >> age;

    switch (age){
    case 18:
        cout<<"your age is 18";
        break;
    
    default:
        cout<<"Your age is not 18";
        break;
    }

    return 0;
}