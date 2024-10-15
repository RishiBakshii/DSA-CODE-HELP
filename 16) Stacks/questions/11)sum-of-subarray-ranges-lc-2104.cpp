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

        while(st.top()!=-1 && arr[st.top()]>=element) st.pop();

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

        while(st.top()!=-1 && arr[st.top()]>element) st.pop();

        nextSmallerIndexArray.push_back(st.top()==-1 ? n : st.top());
        st.push(i);

    }
}

void calculatePrevGreaterIndex(vector<int>&arr,vector<int>&nextSmallerIndexArray){

    stack<int> st;
    st.push(-1);
    int n = arr.size();

    for(int i=0;i<n;i++){

        int element = arr[i];

        while(st.top()!=-1 && arr[st.top()]<=element) st.pop();

        nextSmallerIndexArray.push_back(st.top());
        st.push(i);

    }
}

void calculateNextGreaterIndex(vector<int>&arr,vector<int>&nextSmallerIndexArray){

    stack<int> st;
    st.push(-1);
    int n = arr.size();

    for(int i=n-1;i>=0;i--){

        int element = arr[i];

        while(st.top()!=-1 && arr[st.top()]<element) st.pop();

        nextSmallerIndexArray.push_back(st.top()==-1 ? n : st.top());
        st.push(i);

    }
}

int calculateSumOfSubArrayMinimum(vector<int>&arr,vector<int>&prevSmallerIndexArray,vector<int>&nextSmallerIndexArray){
    
    int minimumSubArraySum=0;

    for(int i=0;i<arr.size();i++){

        long long prevSmallerIndex = prevSmallerIndexArray[i];
        long long nextSmallerIndex = nextSmallerIndexArray[i];

        long long left = (i - prevSmallerIndex);
        long long right = (nextSmallerIndex - i);
        
        long long count = left*right;
        long long sum = count * arr[i];

        minimumSubArraySum = minimumSubArraySum + sum;

    }

    return minimumSubArraySum;
}

int calculateSumOfSubArrayMaximum(vector<int>&arr,vector<int>&prevGreaterIndexArray,vector<int>&nextGreaterIndexArray){
    
    int maximumSubArraySum=0;
    
    for(int i=0;i<arr.size();i++){

        long long prevSmallerIndex = prevGreaterIndexArray[i];
        long long nextSmallerIndex = nextGreaterIndexArray[i];

        long long left = (i - prevSmallerIndex);
        long long right = (nextSmallerIndex - i);
        
        long long count = left*right;
        long long sum = count * arr[i];

        maximumSubArraySum = maximumSubArraySum + sum;

    }

    return maximumSubArraySum;
}


int main(){

    vector<int> arr = {4,-2,-3,4,1};
    vector<int> prevSmallerIndexArray;
    vector<int> nextSmallerIndexArray;
    vector<int> prevGreaterIndexArray;
    vector<int> nextGreaterIndexArray;

    calculatePrevSmallerIndex(arr,prevSmallerIndexArray);
    calculateNextSmallerIndex(arr,nextSmallerIndexArray);

    calculatePrevGreaterIndex(arr,prevGreaterIndexArray);
    calculateNextGreaterIndex(arr,nextGreaterIndexArray);

    reverse(nextSmallerIndexArray.begin(),nextSmallerIndexArray.end());
    reverse(nextGreaterIndexArray.begin(),nextGreaterIndexArray.end());


    int minimumSubArraySum = calculateSumOfSubArrayMinimum(arr,prevSmallerIndexArray,nextSmallerIndexArray);
    int maximumSubArraySum = calculateSumOfSubArrayMaximum(arr,prevGreaterIndexArray,nextGreaterIndexArray);

    int ans = maximumSubArraySum - minimumSubArraySum;
    cout<<minimumSubArraySum<<endl;
    cout<<maximumSubArraySum<<endl;

    cout<<ans<<endl;
      
    return 0;
}