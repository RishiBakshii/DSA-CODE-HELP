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

    for(int i=2;i<n || i*i<=n;i++){

        if(primeOrNot[i]){
            
            // int j=2;

            // optimizition
            // first unmarked number would be *i as others have been marked by 2 to (i-1);
            int j=i;
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
vector<bool> segmentedSeive(int l, int r){
    // this one is as same as sieveOfEratosthenes
    // but is used when we have been given low and high i.e l and h
    // and in that search area we need to find prime numbers

    // generate all primes till sqrt(r)
    vector<bool> seive(sqrt(r),true);

    seive[0]=seive[1]=false;

    for(int i=2;i<seive.size() && i*i<=r;i++){

        if(seive[i]){

            int j=i;
            int iTable = j*i;

            while(iTable<=r){
                seive[iTable]=false;
                iTable=i*++j;
            }

        }

    }

    // basePrimes
    vector<int> basePrimes;
    
    // so in this step we are traversing through the primes
    // that are in range of sqrt(r) that are stored in seive vector
    // and those are are primes we are pushing them in basePrimes vector
    for(int i=0;i<seive.size();i++){
        if(seive[i]) basePrimes.push_back(i);
    }

    // now we are making segmented seive
    vector<bool> segSeive(r-l+1);

    if(l==1 || l==0){
        segSeive[l]=false;
    }

    for(auto prime:basePrimes){

        int firstMul = (l/prime)*prime;

        if(firstMul<l){
            firstMul+=prime;
        }

        int j = max(firstMul,prime*prime);

        while(j<=r){
            segSeive[j-l]=false;
            j+=prime;
        }

    }

    return segSeive;
}

int main(){

    // cout<<sqrtApproch(10);
    // cout<<sieveOfEratosthenes(10);

    int l=90;
    int r=150;

    vector<bool> segSeive = segmentedSeive(l,r);

    for(int i=0;i<segSeive.size();i++){

        if(segSeive[i]){
            cout<<i+l<<endl;
        }

    }
    
    return 0;
}