#include<iostream>
#include<vector>
using namespace std;


void solve(vector<vector<int>>&mat,int n,int&pathsFound,int row, int column,string&ans){
    // base case
    if(row==n-1 && column==n-1){
        pathsFound++;
        cout<<"answer "<<ans;
        return;
    }

    if(row>=n || column>=n || row<0 || column<0) {
        ans.pop_back();
        return;
    }

    if(mat[row][column]==0){
        ans.pop_back();
        return;
    }

    // call for up direction
    if(row-1>=0 && mat[row-1][column]!=0){
        ans.push_back('U');
        mat[row][column]=0;
        solve(mat,n,pathsFound,row-1,column,ans);
    }

    // call for down direction
    if(row+1<n && mat[row+1][column]!=0){
        ans.push_back('D');
        mat[row][column]=0;
        solve(mat,n,pathsFound,row+1,column,ans);
    }

    // call for left direction
    if(column-1>=0 && mat[row][column-1]!=0){
        ans.push_back('L');
        mat[row][column]=0;
        solve(mat,n,pathsFound,row,column-1,ans);
    }

    // call for right direction
    if(column+1<n && mat[row][column+1]!=0){
        ans.push_back('R');
        mat[row][column]=0;
        solve(mat,n,pathsFound,row,column+1,ans);
    }

    return;

}

int main(){
    
    vector<vector<int>> mat = {
        {1,0,0,0},
        {1,1,0,1},
        {1,1,0,0},
        {0,1,1,1},
    };

    vector<string> finalAnswer;
    string ans = "";
    int pathsFound = 0;

    solve(mat,mat.size(),pathsFound,0,0,ans);

    // cout<<ans;

    return 0;
}