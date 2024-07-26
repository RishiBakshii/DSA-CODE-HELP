#include<iostream>
using namespace std;

int isPossibleSolution(int n){

    int cowsCount=0;
    int chickenCount=0;

    int chickenLegs = 2;
    int cowsLegs = 4;
    
    while(n){

        if(n>=cowsLegs){
            cowsCount = n/cowsLegs;
            n=n%cowsLegs;
        }
        else if(n>=chickenCount){
            chickenCount=n/chickenLegs;
            n=n%chickenLegs;
        }

    }

    return cowsCount+chickenCount;

}


int main(){
    
    int t;
    cin>>t;

    while (t--){
        int n;
        cin>>n;
        cout<<isPossibleSolution(n);

    };
    


    return 0;
}