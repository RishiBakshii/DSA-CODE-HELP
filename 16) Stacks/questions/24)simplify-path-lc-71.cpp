/*



class Solution {
public:

    string simplifyPath_helper(string path) {

        stack<string> st;
        int n = path.size();

        string tempString = "";

        for(int i=0;i<n;i++){

            string ch  = string(1,path[i]);
            
            // if the stack is empty then push the string character
            if(st.empty()) st.push(ch);
            
            // if we encounter a closing / slash
            // and some tempString is there
            // i.e the string between / and /
            // then only we consider computing as without this condition
            //  "///" this could be the case
            else if(ch=="/" && tempString!=""){
                
                // we cannot go back if we are already at root i.e "/"
                if(tempString==".." && st.size()>1){
                    st.pop();
                    while(!st.empty() && st.top()!="/") st.pop();
                }
                // if there is a valid tempstring i.e not equal to . or ..
                // then only we push that as a path
                else if(tempString!="." && tempString!=".."){
                    st.push(tempString);
                    st.push("/");
                }

                // resetting the temp string
                tempString="";
            }
            // making tempstring here
            else if(ch!="/") tempString+=ch;

        }


        // after the loop if there is some tempstring left
        if(tempString!=""){
            
            // we cannot go back from root
            if(tempString==".." && st.size()>1){
                st.pop();
                while(!st.empty() && st.top()!="/") st.pop();
            }

            // if there is a valid path then pushing it
            else if(tempString!="." && tempString!=".."){
                st.push(tempString);
                st.push("/");
            }
        }

        // making a vector
        vector<string> v;

        // looping over stack and pushing our answer in vector
        while(!st.empty()){
            if(st.top()!="/") v.push_back(st.top());
            st.pop();
        }

        // reversing the vector as stack reverses our answer
        reverse(v.begin(),v.end());

        // now looping over vector and making our answer back in the correct order
        string ans = "";
        for(int i =0;i<v.size();i++){

            ans+=v[i];
            if(i!=v.size()-1){
                ans+="/";
            }
        }

        // returning the anwer with "/"
        return "/" + ans;
        
    }

    string simplifyPath(string path) {
        return simplifyPath_helper(path);
    }
};

*/