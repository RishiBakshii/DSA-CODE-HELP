#include<iostream>
#include<stack>
using namespace std;

    // the approach of this question is

    // we will push -1 in the stack

    // when we find a pair i.e ( this brakcet is at the top and we find this ) as our current bracket
    // so we pop this ( this one out

    // but during that pop if the stack becomes empty that means the pair was not valid somehow
    // if stack remains non-empty that means the pair was a legit pair and then we try to calculate the count of valid pair


int longestValidParentheses(string s) {
    stack<int> st;
    st.push(-1);
    int maxLen = 0;

    for(int i=0;i<s.size();i++){

        char ch = s[i];

        // if the bracket is of openning ( then push index
        if(ch=='(') st.push(i);

        else{
            // we found the closing bracket, so we will pop to cancel out a pair as a valid pair right?
            st.pop();

            // but if the stack became empty, then it means it was not a valid pair 
            if(st.empty()){

                // and we push the current index so that we can use it to 
                // calculate the lenght of future valid pairs
                st.push(i);
            }
            else{
                // if the stack is not empty, then it means the pair was valid
                int len = i - st.top(); // here st.top() is the index that we pushed during st.empty()
                
                // storing the maxLenght
                // i.e longest valid paranthesis length
                maxLen = max(len,maxLen);
            }
        }

    }

    return maxLen;

}

int main(){
    
    return 0;
}