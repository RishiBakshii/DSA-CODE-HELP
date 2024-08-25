#include<iostream>
using namespace std;

// time complexity
// in fibonnaci if we are stading at 1 position
// and we can go two ways so it;s time complexity was
// 2^n
// but here each dice can go k ways
// so the time complexity will be k^n (which is crazily high)

// space complexity O(n)

int numRollsToTarget(int n, int k, int target){

    // base cases
    if(target<0) return 0;
    if(n==0 && target == 0) return 1;
    if(n==0 && target!=0) return 0;
    if(n!=0 && target == 0) return 0;

    int ans = 0;
    for(int i=1;i<=k;k++){
        ans = ans + numRollsToTarget(n-1,k,target-i);
    }

    return ans;
}


int main(){
    
    int n = 2;
    int k  =6;
    int target = 7;

    cout<<numRollsToTarget(n,k,target);

    return 0;
}