#include<iostream>
#include<vector>
using namespace std;


bool solve(vector<int> nums,int i){

    int n = nums.size();

    // base case
    if(i==n-1) return true;
    if(i>=n) return false;
    bool ans = false;

    for(int k=i+1;k<=nums[i]+i;k++){
        ans = ans || solve(nums,k);
    }

    return ans;

}

// 3
// 2

int main(){

    vector<int> nums = {3,2,1,0,4};
    cout<<solve(nums,0);
    
    return 0;
}