#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
#include<limits.h>
using namespace std;


/*

In this question the approach is


// for every histogram of a specific length, if it need to expand then we need to find the left and right limits of it's expansion right?

// so we can do that with the help of next smallest element and prev smallest element calculating

// as if for every histogram bar if we know the next smallest element of and prev smallest element of it , then we know it's limits of expansion

// but the catch is rather than storing the element we are storing the index of them

// when we have the left and right limit of every bar then we can calculate the widht 
by using this formula
w= next-prev+1;

and then which one is having the largest width we can return that 

// but why we are calulating the next and prev smallest element
as because if we need to expand one bar's widht into others then the other bar should be either tall or of same length if it is small then how can we expand right?

so smaller elements are the limit on each side

and that is why we are calculating the next and prev smaller element in this question

*/

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