#include<iostream>
using namespace std;

void solve(string&str, int s, int e,bool& ans){

    // base case
    if(s>=e){
        return;
    }

    // 1 case
    if(str[s]!=str[e]) {
        ans = false;
        return;
    }

    // re: call
    solve(str,s+1,e-1,ans);

}


int main(){
    
    string s = "rishi";
    bool ans = true;
    solve(s,0,s.size()-1,ans);

    cout<<ans;

    return 0;
}