#include<iostream>
#include<math.h>
#include<limits.h>
using namespace std;

// TC => O(sqrt(n)^n) => O(n^n)
// SC => O(n+1) => O(n)
int numSquares(int n){

    // base case
    if(n==0) return 1;
    if(n<0) return 0;

    int ans = INT_MAX;
    int i=1;

    int end  = sqrt(n);

    while(i<=end){
        
        int perfectSqaure = i*i;
        int numberOfPerfectSqaures = 1 + numSquares(n-perfectSqaure);
        if(numberOfPerfectSqaures < ans) {
            ans = numberOfPerfectSqaures;
        }

        i++;
    }

    return ans;
     

}

int main(){

    int n  = 13;
    cout<<numSquares(n)-1;

    return 0;
}