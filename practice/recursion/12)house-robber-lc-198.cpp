#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;

void solve(vector<int>&arr,int i,int amount,int&ans){

    // base case
    if(i>=arr.size()){
        ans = max(ans,amount);
        return;
    }

    // include
    solve(arr,i+2,amount+arr[i],ans);

    // exclude
    solve(arr,i+1,amount,ans);

}

int main(){
    
    vector<int> nums = {2,7,9,3,1};
    int ans = INT_MIN;
    solve(nums,0,0,ans);

    cout<<"The maximum amount stolen can be "<<ans;
    
    return 0;
}