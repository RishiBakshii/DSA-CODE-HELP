#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;

void solve(vector<vector<int>>&arr,int row,int target,int sum,int&miniAns){

    // base case
    if(row>=arr.size()){
        miniAns = min(miniAns,abs(target-sum));
        return;
    }

    // solving for 1 row
    // baaki recursion sambhal lega
    for(int col=0;col<arr[row].size();col++){
        solve(arr,row+1,target,sum+arr[row][col],miniAns);
    }

}

int main(){
    
    vector<vector<int>> arr = {
        {1,2,3},
        {4,5,6},
        {7,8,9},
    };

    int target = 13;
    int miniAns = INT_MAX;

    solve(arr,0,target,0,miniAns);
    cout<<"The minimum answer is "<<miniAns;

    return 0;
}