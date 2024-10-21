#include<iostream>
#include<stack>
#include<algorithm>
using namespace std;

string removeDuplicates(string s) {

    // if the string size is 1 
    // there are no possible duplicates
    if(s.size()==1) return s;

    stack<char> st;

    // travering over string
    for(auto i:s){
        // if the element we are about to push is  already present at the top
        // then pop that element
        if(!st.empty() && st.top()==i) st.pop();
        // else we push the element in the stack
        else st.push(i);
    }

    s="";

    // traversing over stack to populate the s 
    // with the remaining string inside stack
    while(!st.empty()){
        s+=st.top();
        st.pop();
    }

    // as stack reverses the data
    // reversing the string back
    reverse(s.begin(),s.end());

    return s;
}

int main(){

    cout<<removeDuplicates("azxxzy");
    
    return 0;
}