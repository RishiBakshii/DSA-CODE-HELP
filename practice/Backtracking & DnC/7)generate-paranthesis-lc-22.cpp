#include<iostream>
#include<vector>
using namespace std;

void solve(int n,int openCount, int closeCount,string&output,vector<string>&ans){

    // base case
    if(openCount==n && closeCount==n){
        ans.push_back(output);
        return;
    }

    if(openCount<n){
        output.push_back('(');
        solve(n,openCount+1,closeCount,output,ans);
        output.pop_back(); // backtrack
    }

    if(closeCount<openCount){
        output.push_back(')');
        solve(n,openCount,closeCount+1,output,ans);
        output.pop_back(); // backtrack
    }

}

int main(){
    

    int n=1;

    vector<string> ans;
    string output = "";
    solve(n,0,0,output,ans);

    for(auto i:ans) cout<<i<<endl;

    return 0;
}