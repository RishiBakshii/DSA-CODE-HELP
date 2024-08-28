#include<iostream>
#include<vector>
using namespace std;


void solve(vector<int>&nums,int i,bool&ans){


    // base case
    int n = nums.size();

    if(i==n-1){
        ans=true;
        return;
    }

    if(nums[i]==0 && i!=n-1){
        return;
    }

    int numberOfJumps = nums[i];
    int jump = 1;

    while(jump<=numberOfJumps){
        solve(nums,i+jump,ans);
        jump++;
    }

}

int main(){
    
    vector<int> nums = {2,3,1,1,4};
    bool ans = false;

    solve(nums,0,ans);

    cout<<"The answer is "<<ans;

    return 0;
}