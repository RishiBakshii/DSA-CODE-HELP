// self
// tc and sc = 0(n)

#include<iostream>
using namespace std;

void solve(string s, char ch,int index,int &ans){

    // base case
    if(s[index]==ch){
        ans=index;
        return;
    }
    // base case
    if(index==-1){
        return;
    }

    solve(s,ch,index-1,ans);

}

int main(){
    
    string s = "abcddefdd";
    int ans = 0;
    char ch = 'd';
    solve(s,ch,s.size()-1,ans);

    cout<<"The last occurence of char "<<ch<<" is "<<ans;

    return 0;
}