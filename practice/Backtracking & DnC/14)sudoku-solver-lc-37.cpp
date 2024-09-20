#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;

void printAnswer(vector<vector<char>>&board){

    for(int i=0;i<board.size();i++){

        for(int j=0;j<board[i].size();j++){
            cout<<board[i][j]<<" ";
        }
        cout<<endl;
    }

}

bool isSafe(vector<vector<char>>&board,int row, int col,int num){

    // row check
    for(int i=0;i<board[row].size();i++){
        if(board[row][i]==num) return false;
    }

    // col check
    for(int i=0;i<board.size();i++){
        if(board[i][col]==num) return false;
    }

    // 3x3 grid check
    int startRow = row - (row%3);
    int startColumn = col - (col%3);
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            int translatedRow = i+startRow;
            int translatedColumn = j+startColumn;
            if(board[translatedRow][translatedColumn]==num) return false;
        }
    }


    return true;


}

bool solve(vector<vector<char>>&board){

    for(int i=0;i<board.size();i++){
        for(int j=0;j<board[i].size();j++){

            // whereever we found the empty block
            if(board[i][j]=='.'){
                // we will explore all possibilites 
                // of putting 1 - 9 in that block
                for(int num='1';num<='9';num++){

                    if(isSafe(board,i,j,num)){
                        board[i][j]=num;
                        bool wasPlacementSuccessful = solve(board);
                        if(!wasPlacementSuccessful) {
                            board[i][j]='.';
                        }
                        else{
                            return true;
                        } 
                    }
                }

                // it means we are not able place any number in that block from 1 - 9 
                return false;

            }

        }

    }

    // it means all the block have been filled
    return true;

}

int main(){
    
    vector<vector<char>> board = {
        {'5','3','.','.','7','.','.','.','.'},
        {'6','.','.','1','9','5','.','.','.'},
        {'.','9','8','.','.','.','.','6','.'},
        {'8','.','.','.','6','.','.','.','3'},
        {'4','.','.','8','.','3','.','.','1'},
        {'7','.','.','.','2','.','.','.','6'},
        {'.','6','.','.','.','.','2','8','.'},
        {'.','.','.','4','1','9','.','.','5'},
        {'.','.','.','.','8','.','.','7','9'},
    };

    // cout<<solve(board);
    solve(board);

    printAnswer(board);

    return 0;
}