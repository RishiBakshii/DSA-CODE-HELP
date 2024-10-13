#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
#include<limits.h>
using namespace std;

void printArray(vector<int>&v){
    for(auto i:v) cout<<i<<" ";
    cout<<endl;
}

void findPrevSmallestElement(vector<int>&heights,vector<int>&prevAns){

    stack<int> st;
    st.push(-1);
    int n = heights.size();

    for(int i=0;i<n;i++){

        int element = heights[i];

        while(st.top()!=-1 && heights[st.top()]>=element) st.pop();

        prevAns.push_back(st.top());
        st.push(i);

    }

}

void findNextSmallestElement(vector<int>&heights,vector<int>&nextAns){

    stack<int> st;
    st.push(-1);
    int n = heights.size();

    for(int i=n-1;i>=0;i--){

        int element = heights[i];

        while(st.top()!=-1 && heights[st.top()]>=element) st.pop();
        
        nextAns.push_back(st.top() == -1 ? n : st.top());
        st.push(i);

    }
}

int main(){

    vector<int> heights = {1,1};
    vector<int> prevAns;
    vector<int> nextAns; 
    
    findPrevSmallestElement(heights,prevAns);
    findNextSmallestElement(heights,nextAns);

    reverse(nextAns.begin(),nextAns.end());

    printArray(prevAns);
    printArray(nextAns);

    int maxWidth = INT_MIN;

    // formula for calulating the widht is
    // w = length * ((next-prev)-1)
    // i.e
    // w = height[i] * ((next-prev)-1)

    for(int i=0;i<heights.size();i++){
        int width = heights[i] * ((nextAns[i]-prevAns[i])-1);
        maxWidth = max(width,maxWidth);
    }

    cout<<maxWidth;

    return 0;
}