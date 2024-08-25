#include<iostream>
#include<vector>
using namespace std;

void solve(vector<int>&nums,int start,int end,int n){

    // base case
    if(end==n) return;

    // 1 case handle
    for(int i=start;i<=end;i++){
        cout<<nums[i];
    }

    cout<<endl;

    solve(nums,start,end+1,n);

}


int main(){
    
    vector<int> arr = {1,2,3,4,5};
    int n = arr.size();

    for(int i=0;i<n;i++){

        int &start = i;
        solve(arr,start,start,n);

    }

    return 0;
}