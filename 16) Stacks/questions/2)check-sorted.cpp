#include<iostream>
#include<stack>
#include<limits.h>
using namespace std;

bool solve(stack<int>&s,int element1){

    if(s.empty()) return true;
    
    if(s.top()<element1){
        element1  = s.top();
        s.pop();
        return solve(s,element1);

        s.push(element1); // backtrack
    }
    else{
        return false;
    }
}

int main(){

    stack<int> s;
    s.push(10);
    s.push(20);
    s.push(5);
    s.push(40);
    s.push(50);

    int element1 = INT_MAX;
    
    cout<<solve(s,element1);

    return 0;
}