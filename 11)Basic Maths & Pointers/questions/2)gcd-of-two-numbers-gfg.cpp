#include<iostream>
using namespace std;

int calculateGcd(int a,int b){

    while(a>0 && b>0){

        if(a>b){
            a=a-b;
        }
        else{
            b=b-a;
        }

    }

    return a==0?b:a;

}

int main(){

    int a = 72;
    int b = 24;
    cout<<calculateGcd(a,b);


    return 0;
}