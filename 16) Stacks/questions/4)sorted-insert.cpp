#include<iostream>
#include<stack>
using namespace std;

void printStack(stack<int>&s){
    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
}

void sortedInsert(stack<int>&s,int val){

    // base case
    if(s.empty()){
        s.push(val);
        return;
    }

    if(!s.empty() && s.top()<val){
        s.push(val);
        return;
    }

    int prevTop=s.top();
    s.pop();
    sortedInsert(s,val);

    s.push(prevTop); // backtrack

}

int main(){

    stack<int> s;

    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);

    sortedInsert(s,1);
    printStack(s);
    
    return 0;
}