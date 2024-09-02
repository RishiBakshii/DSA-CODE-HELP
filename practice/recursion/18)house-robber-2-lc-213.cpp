#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;

void solve(vector<int>&nums,int s,int e,int amount,int&ans){

    if(s>e){
        ans = max(amount,ans);
        return;
    }

    // include
    solve(nums,s+2,e,amount+nums[s],ans);

    // exclude
    solve(nums,s+1,e,amount,ans);


}

int main(){
    

    vector<int> nums = {1,2,3,1};
    int ans = INT_MIN;

    solve(nums,0,nums.size()-2,0,ans);
    solve(nums,1,nums.size()-1,0,ans);

    cout<<ans;

    return 0;
}