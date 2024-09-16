#include<iostream>
#include<vector>
using namespace std;

// restricted recursion 
void solve(int n,int openCount, int closeCount,string output,vector<string> &ans){

    // base case
    if(openCount+closeCount == 2*n){
        ans.push_back(output);
        return;
    }

    // open call

    if(openCount<n) {
        output.push_back('(');
        solve(n,openCount+1,closeCount,output+"(",ans);
        output.pop_back(); // backtracking
    }

    // close call
    if(closeCount<openCount) {
        output.push_back(')');
        solve(n,openCount,closeCount+1,output+")",ans);
        output.pop_back(); // backtracking
    }

}

int main(){

    int n = 3;
    vector<string> ans;
    solve(n,0,0,"",ans);

    for(auto i:ans) cout<<i<<endl;
    
    return 0;
}