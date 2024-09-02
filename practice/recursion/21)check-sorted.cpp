#include<iostream>
#include<vector>
using namespace std;

void solve(vector<int>&arr,int i,bool&ans){


    // base case
    if(i==arr.size()-1) return;

    if(arr[i+1]<arr[i]) {
        ans=false;
        return;
    }
    solve(arr,i+1,ans);
}

int main(){
    
    vector<int> arr = {1,2,3,4,5};
    bool ans = true;
    solve(arr,0,ans);

    if(ans) cout<<"Array is sorted";
    else{
        cout<<"Array is not sorted";
    }

    return 0;
}