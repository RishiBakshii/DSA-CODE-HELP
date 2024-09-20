#include<iostream>
#include<vector>
using namespace std;

void printAns(vector<vector<int>>&ans){

    for(int i=0;i<ans.size();i++){

        for(int j=0;j<ans[i].size();j++){
            cout<<ans[i][j];
        }

        cout<<endl;
    }
}

void solve(vector<int>&nums,int i,vector<vector<int>>&ans){

    if(i>=nums.size()-1){
        ans.push_back(nums);
        return;
    }

    // we want 
    // current ith element par
    // har jth element ko rhak kar dheke
    for(int j=i;j<nums.size();j++){
        swap(nums[i],nums[j]);
        solve(nums,i+1,ans);
        swap(nums[i],nums[j]);  // backtracking

    }

}

int main(){

    vector<int> nums = {1,2,3};

    vector<vector<int>> ans;

    solve(nums,0,ans);

    printAns(ans);

    return 0;
}