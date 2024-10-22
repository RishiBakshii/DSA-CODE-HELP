#include<iostream>
using namespace std;

// if we had to do the task within the queue itself
// vector<int> rearrangeQueue(queue<int> &q){
    
//     queue<int> q2;
    
//     int mid = q.size()/2;
    
//     while(mid--){
//         q2.push(q.front());
//         q.pop();
//     }
    
//     while(!q2.empty()){
//         q.push(q2.front());
//         q2.pop();
//         q.push(q.front());
//         q.pop();
//     }
    
//     return q;
// }

// but if vector is allowed then this logic
// vector<int> rearrangeQueue(queue<int> &q){
    
//     vector<int> ans;
//     queue<int> q2;
    
//     int mid = q.size()/2;
    
//     while(mid--){
//         q2.push(q.front());
//         q.pop();
//     }
    
//     while(q2.size()){
//         ans.push_back(q2.front());
//         q2.pop();
//         ans.push_back(q.front());
//         q.pop();
//     }
    
//     return ans;
// }

int main(){
    
    return 0;
}