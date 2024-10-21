#include<iostream>
#include<stack>
#include<string>
#include<algorithm>
using namespace std;

string decodeString_helper(string&s){

    int n = s.size();
    stack<string>st;

    for(int i=0;i<n;i++){
        
        string element = string(1,s[i]);

        if(isdigit(s[i])){
            string wholeDigit = "";
            while(isdigit(s[i])){
                wholeDigit+=s[i];
                i++;
            }

            st.push(wholeDigit);
        }

        // if not brackets i.e pushing alphabets here
        else if(element!="[" && element!="]") st.push(element);
        else if(element=="]"){

            string temp = "";
            string tempResolved = "";

            // ulta jao jab tak number na mile
            while(!st.empty() && !isdigit(st.top()[0])){
                temp+=st.top();
                st.pop();
            }

            int number = stoi(st.top());
            st.pop();

            for(int k=0;k<number;k++) tempResolved+=temp;
            st.push(tempResolved);

        }

    }
    string ans = "";

    while(!st.empty()){
        ans+=st.top();
        st.pop();
    }

    reverse(ans.begin(),ans.end());
    return ans;
}

int main(){

    string s = "3[a2[c]]";
    cout<<decodeString_helper(s);


    
    return 0;
} 