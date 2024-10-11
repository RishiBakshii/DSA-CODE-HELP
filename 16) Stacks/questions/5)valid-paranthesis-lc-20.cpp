#include<iostream>
#include<stack>
using namespace std;

bool solve(string&s,stack<char>&st){

    for(int i=0;i<s.size();i++){

        char bracket = s[i];

        // if openning bracket then push into stack
        if(bracket == '(' || bracket == '{' || bracket == '['){
            st.push(bracket);
        }
        else{
            char topElementInStack =  !st.empty()?st.top():'!';
            // closing bracket
            if(bracket == ')' && topElementInStack == '('){
                st.pop();
            }
            else if(bracket == '}' && topElementInStack == '{'){
                st.pop();
            }
            else if(bracket == ']' && topElementInStack == '['){
                st.pop();
            }
            else return false;
        }

    }

    if(st.empty()) return true;
    return false;
}

int main(){

    stack<char> st;
    string s = "()[]{}";

    bool ans =  solve(s,st);
    cout<<ans;
    
    return 0;
}