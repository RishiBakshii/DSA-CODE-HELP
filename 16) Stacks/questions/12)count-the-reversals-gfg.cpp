#include<iostream>
#include<stack>
using namespace std;

int countRev (string s){
    
    // in case of a odd string of brackets we can't make a valid brakcet string
    // as in brackets we need the pairs and in odd lenght there can't be perfect pairs
    if(s.size()%2!=0) return -1;
    
    int reversalCount = 0;
    stack<char> st;
    

    // valid paranthesis logic
    for(int i=0;i<s.size();i++){
        
        char ch = s[i];

        // if stack is not empty and last bracket is openning and current one is closing
        // then we pop
        if(!st.empty() && st.top()=='{' && ch=='}') st.pop();
        
        // else we push
        else st.push(ch);
        
    }
    
    // if the stack is still not empty that means
    // there are some invalid brackets left

    while(!st.empty()){
        

        // placing prev and curr pointers on stack
        char prev = st.top();
        st.pop();
        char curr = st.top();
        
        // same case
        // if prev and curr are same i.e ( and (  then we need to reverse the last one
        // i.e ( and ) to make them valid so reversal will increase by 1;
        if(prev==curr) reversalCount++;
        
        // if prev and curr bracket are different i.e ) and ( then means we need to reverse them both
        // i.e ( and ) so reversal in this case will increase by 2
        else reversalCount+=2;
        
        // popping from the stack
        st.pop();
        
    }
    
    return st.empty() ? reversalCount : -1;
}

int main(){

    cout<<countRev("(())()()()()");
    
    return 0;
}