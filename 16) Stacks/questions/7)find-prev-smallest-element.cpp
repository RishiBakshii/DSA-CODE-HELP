#include<iostream>
#include<stack>
#include<vector>
#include<algorithm>
using namespace std;

void solve(vector<int>&v,vector<int>&ans,stack<int>&s){

    int n = v.size();

    // reverse iteration
    for(int i=0;i<n;i++){

        int num = v[i];

        // kya top element num se chota hain?
        // agar han, toh yehi answer hain
        // and current NUM ko stack mein push krenge
        if(s.top() < num){
            ans.push_back(s.top());
            s.push(num);
        }
        else{
            // agar top element num se chota nahi hain
            // top pehle toh usse pop krdo
            s.pop();

            // fir loop mein check karo
            // jab tk chota element na mil jaye stack ke top mein
            while(!s.empty()){
                if(s.top()<num){
                    ans.push_back(s.top());
                    s.push(num);
                    break;
                }
                else s.pop();
            }
        }

    }
}

int main(){

    vector<int> v = {8,4,6,2,3};
    vector<int> ans;

    stack<int> s;

    // pehle se stack pr -1 hoga 
    // kyuki default answer yehi hota hain 
    // jab koi smallest number nahi milta
    s.push(-1);

    solve(v,ans,s);

    // printing ans
    for(auto i:ans) cout<<i<<" ";
    
    return 0;
}