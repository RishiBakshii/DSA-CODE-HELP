#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;

void solve(vector<int>&arr, int i, int sum,int&ans){

    cout<<sum<<endl;

    // base case
    if(i>=arr.size()) {
        ans = max(ans,sum);
        return;
    }

    // include
    if(i+2!=(arr.size()-1)){
        solve(arr,i+2,arr[i]+sum,ans); 
    }
    else{
        ans = max(sum+arr[i],ans);
    }

    solve(arr,i+1,sum,ans); 
    // exclude
}

int main(){
    

    vector<int> arr = {1,2,1,1};
    int ans = INT_MIN;
    solve(arr,0,0,ans);

    cout<<"The answer is "<<ans;

    return 0;
}