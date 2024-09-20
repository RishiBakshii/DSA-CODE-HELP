#include<iostream>
#include<vector>
using namespace std;

bool isSafe(vector<vector<int>>&mat,int newX, int newY){

    // out of bound check
    if(newX<0 || newX>=mat.size() || newY<0 || newY>=mat[0].size()) return false;

    // already visited check
    if(mat[newX][newY]==0) return false;

    return true;
}

void solve(vector<vector<int>>&mat,string&path,int currX,int currY,int destX, int destY,vector<string>&ans){

    // base case
    if(currX==destX && currY==destY){
        // we have reached the destination
        ans.push_back(path);
        return;
    }

    vector<int> dx = {-1,0,1,0};
    vector<int> dy = {0,-1,0,1};
    vector<char> directions = {'U','L','D','R'};

    // exploring all 4 directions
    for(int i=0;i<directions.size();i++){


        int newX = currX + dx[i];
        int newY = currY + dy[i];

        if(isSafe(mat,newX,newY)){

            path.push_back(directions[i]);
            mat[newX][newY] = 0;

            solve(mat,path,newX,newY,destX,destY,ans);

            // bactracking
            path.pop_back();
            mat[newX][newY] = 1;
        }


    }
}

int main(){

    vector<vector<int>> mat = {
        {1,0,0,1},
        {1,1,0,1},
        {1,1,0,0},
        {0,1,1,1},
    };

    vector<string> ans;

    if(mat[0][0]==0) {
        return 0;
    }

    int currX = 0;
    int currY = 0;
    int destX = mat.size()-1;
    int destY = mat[0].size()-1;

    // marking the currX and currY as visited
    // as we are already standing there initially
    mat[currX][currY]=0;

    string path = "";

    solve(mat,path,currX,currY,destX,destY,ans);

    // prining ans
    for(auto i:ans) cout<<i<<endl;
    
    return 0;
}