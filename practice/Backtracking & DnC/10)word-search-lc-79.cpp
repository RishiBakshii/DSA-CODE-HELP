#include<iostream>
#include<vector>
using namespace std;

bool isSafe(vector<vector<char>>&board,int newX,int newY,string&word,int charactersFound){

    // out of bound check
    if(newX<0 || newX>=board.size() || newY<0 || newY>=board[newX].size()) return false;

    // already visited check
    if(board[newX][newY]=='.') return false;

    // if newCell does not have the character we are looking for
    if(board[newX][newY]!=word[charactersFound]) return false;
    

    return true;
}

void solve(vector<vector<char>>&board,string&word,int currX,int currY,int charactersFound,bool&ans){

    // base case
    if(charactersFound>=word.size()){
        ans=true;
        return;
    }

    // checking all directions
    vector<int> dx = {-1,0,1,0};
    vector<int> dy = {0,-1,0,1};
    vector<char> directions = {'U','L','D','R'};

    for(int d=0;d<directions.size();d++){

        int newX = currX + dx[d];
        int newY = currY + dy[d];

        if(isSafe(board,newX,newY,word,charactersFound)){

            // marking visited
            char temp = board[newX][newY];
            board[newX][newY]='.';
            solve(board,word,newX,newY,charactersFound+1,ans);

            // backtracking
            board[newX][newY]=temp;
        }
    }

}

int main(){

    vector<vector<char>> board = {
        {'A','B','C','E'},
        {'S','F','C','S'},
        {'A','D','E','E'},
    };

    string word = "ABCB";

    bool ans = false;
    int charactersFound = 0;

    for(int i=0;i<board.size();i++){
        for(int j=0;j<board[i].size();j++){
            if(board[i][j]==word[0]){

                // storing the co-ordinates value
                char temp = board[i][j];

                // marking as visited
                board[i][j]='.';
                solve(board,word,i,j,charactersFound+1,ans);

                // backtrack (marking unvisited)
                board[i][j]=temp;

                // if the word is found then no need to move forward
                if(ans) break;
            }
        }
    }

    cout<<ans;
    
    return 0;
}