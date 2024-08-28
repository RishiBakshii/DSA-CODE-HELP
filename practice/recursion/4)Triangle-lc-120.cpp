#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;


void solve(vector<vector<int>>&triangle,int row,int column,int sum,int&ans){

    // base case
    if(row==triangle.size()){
        // here we will compare the sum with ans
        ans = min(sum,ans);
        return;
    }

    // call for current column in the next row
    solve(triangle,row+1,column,sum+triangle[row][column],ans);

    // call for current column + 1 in the new row
    solve(triangle,row+1,column+1,sum+triangle[row][column+1],ans);

}

int main(){
    
    vector<vector<int>> triangle = {

        {-1},
        {2,3},
        {1,-1,-3},
    };

    int ans = INT_MAX;

    solve(triangle,1,0,triangle[0][0],ans);

    cout<<"The answer is "<<ans;



    return 0;
}