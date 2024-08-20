#include<iostream>
#include<vector>
using namespace std;

int solve(vector<vector<int>>&mat,int target,int rowSize, int colSize, int currentRow, int currentColumn){

    // base case
    if(currentRow==rowSize || currentColumn==colSize){
        return;
    }

    

}

int main(){
    

    vector<vector<int>> mat = {{1,2,9,8,7}};
    int target = 6;

    int rowSize = mat.size();
    int colSize = mat[0].size();

    vector<int> ans;

    solve(mat,target,rowSize,colSize,0,0);

    return 0;
}