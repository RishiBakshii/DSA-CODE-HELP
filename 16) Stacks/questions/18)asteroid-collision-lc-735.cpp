/*
class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        for(int i = 0;i<asteroids.size();i++){

            int ast = asteroids[i];

            // if stack is empty then push any asteroid
            if(st.empty()) st.push(ast);
            else{
                // stack is not empty
                if(st.top()>0 && ast<0){
                    // collision will happen
                    // as lastest ast in stack is going right and curr one is going left

                    // checking if the coming asteroid is big enough to destory the prev asteroid

                    bool isDestroyed = false;
                    
                    while(!st.empty() && st.top()>0){
                        if(abs(ast)>abs(st.top())){
                            st.pop();
                        }
                        else if(abs(ast)<abs(st.top())) {
                            isDestroyed=true;
                            break;
                        }
                        else if(abs(ast)==abs(st.top())){
                            isDestroyed=true;
                            st.pop();
                            break;
                        }
                    }
                    
                    if(!isDestroyed) st.push(ast);
                    

                }
                else{
                    st.push(ast);
                }
            }

        }

        vector<int> ans(st.size());

        for(int i=ans.size()-1;i>=0;i--){
            ans[i]=st.top();
            st.pop();
        }

        return ans;
    }
    
};

*/