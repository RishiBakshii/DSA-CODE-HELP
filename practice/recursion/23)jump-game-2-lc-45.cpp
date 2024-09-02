#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;

void solve(vector<int>&arr,int i,int jumpCount,int&ans){

    // base case
    if(i>arr.size()) return;

    if(i==arr.size()-1){
        ans = min(ans,jumpCount);
        return;
    }

    int jumps = arr[i];
    int numberOfJumps = 1;

    while(numberOfJumps<=jumps){
        if(i+numberOfJumps<arr.size()) {
            solve(arr,i+numberOfJumps,jumpCount+1,ans);
        }
        numberOfJumps++;
    }

}

int main(){
    
    vector<int> arr = {1,2};
    int ans = INT_MAX;

    solve(arr,0,0,ans);

    cout<<"The minimum number of jumps is "<<ans;

    return 0;
}