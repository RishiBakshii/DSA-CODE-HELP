/*

what is the role of ans here?
=> here ans basically tell us if at any given point the string is ended
then how many brackets we will be needing to make it a valid paranthesis

class Solution {
public:
    int minAddToMakeValid(string s) {

        stack<char> st;
        int ans =0;

        for(int i=0;i<s.size();i++){

            char ch = s[i];

            if(ch=='(') {
                st.push(ch);
                ans++;
            }

            else{
                if(st.empty()){
                    ans++;
                }
                else{
                    if(!st.empty() && st.top()=='('){
                        st.pop();
                        ans--;
                    }
                }
            }

        }

        return ans;

    }
};

*/