#include<iostream>
#include<stack>
using namespace std;

int main(){
    stack<char> s;
    string name = "rishibakshi";

    // insertion of characters into the stack
    for(int i=0;i<name.size();i++){
        s.push(name[i]);
    }

    // retreival of characters from the stack
    while(!s.empty()){
        cout<<s.top();
        s.pop();
    }

    
    return 0;
}