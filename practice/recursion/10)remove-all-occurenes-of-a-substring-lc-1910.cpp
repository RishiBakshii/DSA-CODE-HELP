#include<iostream>
using namespace std;

void solve(string&s,string part){

    int patternStartingIndex = s.find(part);

    if(patternStartingIndex==string::npos) return;

    string leftPart = s.substr(0,patternStartingIndex);
    string rightPart = s.substr(patternStartingIndex+part.size(),s.size());

    s = leftPart+rightPart;

    solve(s,part);

}

int main(){

    string s = "daabcbaabcbc";
    string part = "abc";

    cout<<"Before"<<endl;
    cout<<s<<endl<<endl;

    solve(s,part);

    cout<<"After"<<endl;
    cout<<s<<endl<<endl;


    
    return 0;
}