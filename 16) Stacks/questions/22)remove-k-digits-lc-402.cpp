#include<iostream>
#include<stack>
#include<algorithm>
using namespace std;

    string removeKdigits(string num, int k) {

        // if we need to remove k numbers to make the smallest number
        // and num.size == k then 0 will be the smallest number
        if(num.size() == k ) return "0";

        stack<char> st;
        
        int n = num.size();
        int i = 0;

        while(i<n){
            
            // if the stack is empty then push the number
            if(st.empty()) st.push(num[i]);

            // if stack is not empty
            else{
                // and the coming number is smaller than the number we selected and push and top of our stack
                if(num[i]<st.top()){

                    // popping out all the big numbers as we can keep the small number
                    // to make our number smallest
                    while(!st.empty() && st.top()>num[i] && k) {
                        st.pop();
                        k--;
                    }

                    // and at the end pushing our num[i] i.e current number
                    st.push(num[i]);
                }
                else{
                    // if the upcoming number is bigger than st.top() number then just push it
                    st.push(num[i]);
                }
            }

            i++;

        }

        // if the k is still left then we need to pop k items from stack
        // this will happend in the case of num = "112"
        while(k>0){
            st.pop();
            k--;
        }


        string ans = "";

        bool areThereOnlyZeros = true;

        while(!st.empty()){
            char ch = st.top();
            if(ch!='0') areThereOnlyZeros=false;
            ans+=st.top();
            st.pop();
        }

        // if there are only zeros in the ans then return "0" , no need to remove leading zeroes
        // as removing leading zeros in this case will remove all the zeros
        if(areThereOnlyZeros) return "0";

        reverse(ans.begin(),ans.end());

        // removing leading zeroes
        int nonZeroIndex = 0;
        i=0;
        while(ans[i]=='0') i++;
        ans = ans.substr(i,ans.size());
        return ans;
        
    }

int main(){
    
    return 0;
}