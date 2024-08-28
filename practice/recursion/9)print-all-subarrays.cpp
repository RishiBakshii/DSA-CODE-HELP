#include<iostream>
#include<vector>
using namespace std;

void solve(int start,int end,vector<int>&arr){


    // base case
    if(end==arr.size()) return;

    for(int i=start;i<=end;i++){
        cout<<arr[i];
    }
    cout<<endl;

    solve(start,end+1,arr);


}

int main(){

    vector<int> arr = {1,2,3,4,5,6,7,8};

    for(int i=0;i<arr.size();i++){
        solve(i,i,arr);
    }
    
    return 0;
}