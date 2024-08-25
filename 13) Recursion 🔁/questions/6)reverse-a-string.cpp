#include<iostream>
using namespace std;

void solve(string&s,int start, int end){

    // base case
    if(start>=end){
        return;
    }

    swap(s[start],s[end]);

    solve(s,start+1,end-1);

}

int main(){
    
    string s = "hello";
    solve(s,0,s.size()-1);
    cout<<s;

    return 0;
}