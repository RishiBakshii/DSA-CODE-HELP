#include<iostream>
#include<stack>
using namespace std;

void printStack(stack<int>&s){
    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
}

void insertAtBottom(stack<int>&s,int value){

    // base case
    if(s.empty()) {
        s.push(value);
        return;
    }

    int prevTop = s.top();
    s.pop();
    insertAtBottom(s,value);

    s.push(prevTop); //backtrack
}

void reverseStack(stack<int>&s){

    // base case
    if(s.empty()) return;

    int prevTop = s.top();
    s.pop();
    reverseStack(s);

    insertAtBottom(s,prevTop);
}

int main(){
    
    stack<int> s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);

    reverseStack(s);
    printStack(s);

    return 0;
}