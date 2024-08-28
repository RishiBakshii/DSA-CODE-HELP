#include<iostream>
using namespace std;

void solve(string&s,int start,int end,bool&ans){

    // base case
    if(start>=end){
        return;
    }

    if(s[start]!=s[end]) {
        ans = false;
        return;
    }

    solve(s,start+1,end-1,ans);

}

int main(){
    string s = "racecar";
    bool ans = true;
    solve(s,0,s.size()-1,ans);

    if(ans) cout<<"This string is a valid palindrome";
    else cout<<"This string is not a valid palindrome";

    return 0;
}