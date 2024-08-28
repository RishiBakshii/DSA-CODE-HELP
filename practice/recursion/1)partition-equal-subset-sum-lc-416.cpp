#include<iostream>
#include<vector>
#include<numeric>
using namespace std;

void solve(vector<int>&arr,int sum,int target,int i,bool&ans){

    // base case
    if(sum==target){
        ans = true;
        return;
    }
    if(i>=arr.size()){
        return;
    }


    // include
    solve(arr,sum+arr[i],target,i+1,ans);

    // exclude
    solve(arr,sum,target,i+1,ans);

}

int main(){

    vector<int> nums = {14,9,8,4,3,2};
    bool ans = false;
    int sum = accumulate(nums.begin(),nums.end(),0);

    if(sum&1){
        ans = false;
    }
    else{
        solve(nums,0,sum/2,0,ans);
    }

    cout<<"the answer is "<<ans;


    return 0;
}