#include<iostream>
using namespace std;


int slowExponentiation(int a, int b){

    // TC => O(b)

    int ans=1;

    for(int i=0;i<5;i++){
        ans*=a;
    }

    return ans;

}

int fastExponentiation(int a, int b){

    // TC => O(logb)

    int ans=1;

    while(b>0){

        if(b&1){
            // odd
            ans*=a;
        }
        a = a*a;
        b/=2;

    }

    return ans;

}

int main(){
    

    cout<<slowExponentiation(2,5)<<endl;
    cout<<fastExponentiation(2,5)<<endl;

    return 0;
}