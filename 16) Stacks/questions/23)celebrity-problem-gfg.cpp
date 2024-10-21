/*

class Solution {
  public:
    // Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& mat) {
        
        stack<int> st;
        int n = mat.size();
        
        // 1. pushing all person into the stack
        for(int i=0;i<n;i++) st.push(i);
        
        // 2. using discard method to filter out people that are not mightBeCelebrity
        while(st.size()!=1){
            
            int personA  = st.top(); st.pop();
            int personB = st.top(); st.pop();
            
            if(mat[personA][personB]){
                // if person a knows person b, then b must be the celebrity
                st.push(personB);
            }
            else{
                // if personA does not know person b 
                // then person A must the celebrity
                st.push(personA);
            }
            
        }
        
        // now after this loop ends there will be single person remaining in the stack
        // that can possibly be a celebrity
        // so we need to run checks to ensure that
        
        int mightBeCelebrity = st.top(); st.pop();
        
        // check 1:
        // all the columns of celebrity must be 0;
        // i.e the celebrity must not know anybody
        for(int i=0;i<n;i++){
            if(mat[mightBeCelebrity][i]!=0) return -1;
        }
        
        // check 2:
        // all other persons must know this mightBeCelebrity
        // i.e in all the rows the column of mightBeCelebrity number must be 1;
        for(int i=0;i<n;i++){
            if(i!=mightBeCelebrity && mat[i][mightBeCelebrity] == 0) return -1;
        }
        
        // if this checks also passed then it is confirmed that 
        // mightBeCelebrity is an actual celebrity
        return mightBeCelebrity;
        
        
    }
};

*/