#include<iostream>
#include<vector>
#include<numeric>
using namespace std;

bool solve(vector<int>&nums, int target, int i){


    // base case
    if(target < 0 || i==nums.size()) return false;
    if(target == 0 ) return true;

    bool includeAns = solve(nums,target - nums[i],i+1);
    bool exludeAns = solve(nums,target,i+1);

    return includeAns || exludeAns;

}

int main(){

    vector<int> nums = {1,2,3,5};
    int sum = accumulate(nums.begin(),nums.end(),0);

    if(sum&1) return false;

    int target = sum>>1;
    
    cout<<solve(nums,target,0);
    
    
    return 0;
}