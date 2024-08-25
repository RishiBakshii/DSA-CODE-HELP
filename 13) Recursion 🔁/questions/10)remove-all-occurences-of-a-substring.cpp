#include<iostream>
using namespace std;

// void solve(string&s,string&part){

//     // base case
//     if(s.find(part)==string::npos) return;

//     // erase
//     s.erase(s.find(part),part.size());

//     // re: call
//     solve(s,part);

// }

// tc => O(n*m)
// sc => O(n/m)
void solve(string&s,string&part){

    // base case
    if(s.find(part)==string::npos) return;

    // erase
    int startIndex = s.find(part);
    s = s.substr(0,startIndex) + s.substr(startIndex+part.size(),s.size());

    // re: call 
    solve(s,part);

}

int main(){
    
    string s = "daabcbaabcbc";
    string part = "abc";

    solve(s,part);

    cout<<s;

    return 0;
}