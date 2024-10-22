#include<iostream>
#include<queue>
#include<stack>
using namespace std;

void reverseQueueUsingStack(queue<int>&q){

    stack<int> st;

    while(!q.empty()) {
        st.push(q.front()); 
        q.pop();
    }

    while(!st.empty()) {
        q.push(st.top());
        st.pop();
    }
        
}

void reverseQueueUsingRecursion(queue<int>&q){ 

    // base case
    if(q.empty()) return;

    int front = q.front();
    q.pop();

    reverseQueueUsingRecursion(q);

    q.push(front); // backtrack

} 
 
void printQueue(queue<int>&q){
    while(!q.empty()){
        cout<<q.front()<<" ";
        q.pop();
    }
    cout<<endl;
}

int main(){
    

    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    q.push(6);

    reverseQueueUsingStack(q);

    // reverseQueueUsingRecursion(q);

    printQueue(q);


    return 0;
}