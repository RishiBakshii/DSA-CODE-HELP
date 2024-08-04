#include<iostream>
#include<math.h>
#include<vector>
using namespace std;

// 1
int countPrimesNavieApproch(int n) {

    // TC => O(n2);

    if(n==0){
        return 0;
    }

    int count=0;

    // this loop is needed
    for(int i=2;i<n;i++){
        
        bool isPrime = true;
        int currentNum = i;

        // but this needs to be optimized
        // so that it does not goes till n i.e currentNum
        for(int j=2;j<currentNum;j++){
            if(currentNum%j==0){
                isPrime=false;
                break;
            }
        }

        if(isPrime) count++;

    }

    return count;
}

/* let's say we n= 10
and we are trying to find out if 10 is a prime number or not
prime number has exactly two factors 
let's take em as a and b
a * b  = n
if (a > sqrt(n) && b > sqrt(n)){
    return false;
}

** atleast one of the factor must be smaller than sqrt(n)
 
*/

// 2
int sqrtApproch(int n){

    // TC => O(n*sqrt(n))
    if(n==0){
        return 0;
    }

    int count=0;

    for(int i=2;i<n;i++){
        
        bool isPrime = true;
        int currentNum = i;
        int sqrtCurrentNum = sqrt(i);

        // now we will only check till sqrt(n)
        // TC => O(sqrt(n))
        for(int j=2;j<=sqrtCurrentNum;j++){
            if(currentNum%j==0){
                isPrime=false;
                break;
            }
        }

        if(isPrime) count++;

    }

    return count;
}


// 3
int sieveOfEratosthenes(int n){

    // O(n * log (logn) )
    
    if(n==0) return 0;

    // marking everynumber prime i.e true
    vector<bool> primeOrNot(n,true);

    // 0th and 1th is a non-prime number
    primeOrNot[0] = primeOrNot[1] = false;

    int ans = 0;
    int count=0;

    for(int i=2;i<n;i++){

        if(primeOrNot[i]){
            
            int j=2;
            int tableNum = i*j;

            while(tableNum<=n-1){
                primeOrNot[tableNum]=false;
                tableNum=i*++j;
            }
        }
    }

    for(auto b:primeOrNot) {
        if(b) count++;
    }

    return count;
}


// 4


int main(){

    // cout<<sqrtApproch(10);
    cout<<sieveOfEratosthenes(10);
    
    return 0;
}