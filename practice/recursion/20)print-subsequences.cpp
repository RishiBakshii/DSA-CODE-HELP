#include<iostream>
#include<vector>
using namespace std;

void solve(string s,int i,string subSequence,vector<string>&ans){

    if(i==s.size()){
        ans.push_back(subSequence);
        return;
    }

    // include
    solve(s,i+1,subSequence+s[i],ans);

    // exclude
    solve(s,i+1,subSequence,ans);


}

int main(){
    
    string s = "xy";
    vector<string> ans;
    solve(s,0,"",ans);

    for(auto i:ans) cout<<i<<endl;

    return 0;
}