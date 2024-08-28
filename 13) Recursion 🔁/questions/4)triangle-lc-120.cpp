#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;

    int solve(vector<vector<int>> &triangle,int sum,int row, int&ans, int col)
    {
        if (row == triangle.size())
        {
            return 0;
        }
        int down = triangle[row][col] + solve(triangle, row + 1, col);
        int plus = triangle[row][col] + solve(triangle, row + 1, col + 1);
        return min(down, plus);
    }

int main(){
    
    int ans = INT_MAX;

    vector<vector<int>> triangle = {{2},{3,4},{6,5,7},{4,1,8,3}};
    // vector<vector<int>> triangle = {{-1},{2,3},{1,-1,-3}};
    // vector<vector<int>> triangle = {{2},{2,6},{4,5,6}};

    if(triangle.size()==1){
        ans = triangle[0][0];
        cout<<"The answer is "<<ans;
    }
    else{
        int sum = triangle[0][0];
        int row = 1;
        int col = 0;

        solve(triangle,sum,row,ans,col);
        cout<<"The answer is "<<ans;
    }


    return 0;
}