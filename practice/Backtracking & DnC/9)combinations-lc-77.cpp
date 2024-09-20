#include<iostream>
#include<vector>
using namespace std;

void printAnswer(vector<vector<int>>&ans){

    for(int i=0;i<ans.size();i++){

        for(int j=0;j<ans[i].size();j++){
            cout<<ans[i][j];
        }

        cout<<endl;
    }

}

void solve(int n,int k,int i,vector<int>&output,vector<vector<int>>&ans){

    // base case
    if(output.size()==k){
        ans.push_back(output);
        return;
    }

    for(int j=i+1;j<=n;j++){
        output.push_back(j);
        solve(n,k,j,output,ans);
        output.pop_back(); // backtrack
    }

}

int main(){
    

    vector<vector<int>> ans;
    vector<int> output;

    int n = 4;
    int k = 2;

    solve(n,k,0,output,ans);

    printAnswer(ans);

    return 0;
}