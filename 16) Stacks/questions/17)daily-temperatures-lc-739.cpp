/*

class Solution {
public:

    void dailyTemperatures_helper(vector<int>&temperatures,vector<int>&ans){

        int n = temperatures.size();
        stack<int> st;
        st.push(0);

        for(int i=n-1;i>=0;i--){

            if(st.top()==0){
                ans.push_back(0);
                st.push(i);
            }
            else{
                while(st.top()!=0 && temperatures[st.top()]<=temperatures[i]) st.pop();

                if(st.top()==0){
                    ans.push_back(0);
                    st.push(i);
                }
                else{
                    int days = st.top() - i;
                    ans.push_back(days);
                    st.push(i);
                }
            }

        }

    }

    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int>ans;
        dailyTemperatures_helper(temperatures,ans);
        reverse(ans.begin(),ans.end());
        return ans;        
    }
};

*/