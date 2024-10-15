#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
using namespace std;

void print(vector<int>&arr){
    for(auto i:arr) cout<<i<<" ";
    cout<<endl;
}

void calculatePrevSmallerIndex(vector<int>&arr,vector<int>&prevSmallerIndexArray){

    stack<int> st;
    st.push(-1);

    for(int i=0;i<arr.size();i++){

        int element = arr[i];

        while(st.top()!=-1 && arr[st.top()]>element) st.pop();

        prevSmallerIndexArray.push_back(st.top());
        st.push(i);

    }


}


void calculateNextSmallerIndex(vector<int>&arr,vector<int>&nextSmallerIndexArray){

    stack<int> st;
    st.push(-1);
    int n = arr.size();

    for(int i=n-1;i>=0;i--){

        int element = arr[i];

        while(st.top()!=-1 && arr[st.top()]>=element) st.pop();

        nextSmallerIndexArray.push_back(st.top()==-1 ? n : st.top());
        st.push(i);

    }
}

int main(){

    vector<int> arr = {85,93,93,90};
    vector<int> prevSmallerIndexArray;
    vector<int> nextSmallerIndexArray;

    calculatePrevSmallerIndex(arr,prevSmallerIndexArray);
    calculateNextSmallerIndex(arr,nextSmallerIndexArray);
    reverse(nextSmallerIndexArray.begin(),nextSmallerIndexArray.end());

    print(prevSmallerIndexArray);
    print(nextSmallerIndexArray);


    int minimumSubArraySum = 0;

    const int mod = 1e9 + 7;

    for(int i=0;i<arr.size();i++){

        int prevSmallerIndex = prevSmallerIndexArray[i];
        int nextSmallerIndex = nextSmallerIndexArray[i];

        int left = (i - prevSmallerIndex)%mod;
        int right = (nextSmallerIndex - i)%mod;
        
        int count = (left*right)%mod;
        int sum = (count * arr[i])%mod;

        minimumSubArraySum = (minimumSubArraySum + sum)%mod;

    }

    cout<<minimumSubArraySum;

    
    return 0;
}