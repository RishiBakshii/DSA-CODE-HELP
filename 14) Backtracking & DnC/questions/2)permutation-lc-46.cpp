#include<iostream>
#include<vector>
using namespace std;

void solve(string&s,int i,string&output,vector<string>&ans){

    // base case
    if(i==s.size()-1) {
        ans.push_back(output);
        return;
    }

    // we want 
    // current ith element par
    // har jth element ko rhak kar dheke
    for(int j=i;j<s.size();j++){
        string newString = output;
        swap(newString[i],newString[j]);
        solve(s,i+1,newString,ans);
    }

}

int main(){

    string s = "ab";
    vector<string> ans;

    solve(s,0,s,ans);

    for(auto i:ans) cout<<i<<endl;

    return 0;
}