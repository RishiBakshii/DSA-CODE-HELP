#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

/*
Diagonals Intuition:

Upper Diagonal (↘):
Cells that lie on the same upper diagonal share the same value for row - col.
Example: (0,0), (1,1), (2,2) all lie on the same diagonal because row - col is the same for all.

Lower Diagonal (↗):
Cells that lie on the same lower diagonal share the same value for row + col.
Example: (0,3), (1,2), (2,1) all lie on the same diagonal because row + col is the same for all.


Why row - col and row + col?
row - col uniquely identifies each upper diagonal.
row + col uniquely identifies each lower diagonal.
*/

void printArray(vector<vector<string>>&ans){

    for(int i=0;i<ans.size();i++){


        for(int j=0;j<ans[i].size();j++){
            cout<<ans[i][j];
            cout<<endl;
        }

        cout<<endl;
    }

}

unordered_map<int,bool> rowMap;
unordered_map<int,bool> lowerDiagonalMap;
unordered_map<int,bool> upperDiagonalMap;

bool isSafe(int row,int col){

    if(rowMap[row]) return false;
    if(lowerDiagonalMap[row-col]) return false;
    if(upperDiagonalMap[row+col]) return false;

    return true;

}

void storeAnswer(vector<vector<char>>&board,vector<vector<string>>&ans){

    vector<string> tempAns;

    for(int i=0;i<board.size();i++){

        string colString = "";

        for(int j=0;j<board.size();j++){
            colString+=board[i][j];
        }

        tempAns.push_back(colString);

    }

    ans.push_back(tempAns);

}

void solve(vector<vector<char>>&board,int queens,int col,vector<vector<string>>&ans){

    // base case
    if(queens<=0){
        storeAnswer(board,ans);
    }

    for(int row=0;row<board.size();row++){

        // calling for each row to place the queens
        if(isSafe(row,col)){

            board[row][col]='Q';
            rowMap[row]=true;
            lowerDiagonalMap[row-col]=true;
            upperDiagonalMap[row+col]=true;

            solve(board,queens-1,col+1,ans);

            // backtracking
            board[row][col]='.';
            rowMap[row]=false;
            lowerDiagonalMap[row-col]=false;
            upperDiagonalMap[row+col]=false;
        }
        
    }
}

int main(){


    int n=4;
    vector<vector<string>> ans;

    vector<vector<char>> board(n,vector<char>(n,'.'));

    solve(board,n,0,ans);

    printArray(ans);

    return 0;
}