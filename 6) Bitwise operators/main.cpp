// Bitwise operators

/*
& (and)  -> only return 1 if both are 1 or (true)
| (or)
^ (xor)
~ (not)
<< (left shift)
>> (right shift)
*/

#include<iostream>
using namespace std;

void checkEvenorOddByAnd(int number){

    if(number&1){
        cout<<number<<" is an odd number";
    }
    else{
        cout<<number<<" is an even number";
    }
}

int calculateSetBitCount(int number){

    int count=0;

    while(number!=0){

        int lastBit = number&1;
        
        if(lastBit){
            count++;
        }

        number=number>>1;
    }

    return count;

}

bool checkPrime(int n){

    bool isPrime=true;

    for(int i=2;i<n;i++){

        if(n%i==0){
            isPrime=false;
            break;
        }

    }

    return isPrime;

}

void printPrimeInRange(int n){

    for(int i=0;i<=n;i++){
        if(i%2==0){
            cout<<i<<endl;
        }
    }

}

int main(){
    
    int n=2;
    // checkEvenorOddByAnd(n);
    // cout<<calculateSetBitCount(4);
    // cout<<checkPrime(13);
    printPrimeInRange(10);

    return 0;
}