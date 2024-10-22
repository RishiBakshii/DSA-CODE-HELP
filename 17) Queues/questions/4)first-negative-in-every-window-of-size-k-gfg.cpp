#include<iostream>
#include<queue>
using namespace std;

vector<long long> printFirstNegativeInteger(long long int A[],long long int N, long long int K) {
    
    
    vector<long long> ans;
    queue<long long> q;
    
    // initilizaing the window
    for(int i=0;i<K;i++){
        
        // storing the index of only negative elements
        if(A[i]<0) q.push(i);
    }
    
    // storing the answer of first window
    if(q.empty()) ans.push_back(0);   // in case of empty store 0 answer for that window that means, no negative element was there for this window
    else ans.push_back(A[q.front()]); 
    
    
    // now window will continue from kth position
    for(int i=K;i<N;i++){
        
        // removal of previous window answer from queue
        if(!q.empty() && q.front()<i-K+1) q.pop();
        
        // storing the index of element in the queue that is negative
        if(A[i]<0) q.push(i);
        
        // storing the answer of the current window 
        if(q.empty()) ans.push_back(0);
        else ans.push_back(A[q.front()]);
        
    }
    
    return ans;
                                                 
}

int main(){

    
    
    return 0;
}