#include<iostream>
#include<queue>
#include<stack>
using namespace std;



void reverseInkGroups(queue<int>&q,int k,int remaningElements){

    // base case
    // when the count of remaningElements is less than k
    if(remaningElements<k){
        
        // popping the elements from queue
        // and pushing that into queue again
        // as because we want to maintain the order
        // but just want to push it backwards
        while(remaningElements){
            int element = q.front();
            q.pop();
            q.push(element);
            remaningElements--;
        }

        return;
    }

    stack<int> st;

    // push 3 elements in stack and pop from queue
    while(st.size()!=3){
        st.push(q.front());
        q.pop();
    }

    // push into the queue again from stack
    // i.e reversing
    while(!st.empty()){
        q.push(st.top());
        st.pop();
    }

    // remaining element == size of queue
    // as now we have reversed k items so the remaning elements are
    // remaningElements-k
    reverseInkGroups(q,k,remaningElements-k);

}

int main(){
    
    queue<int> q;
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(35);
    q.push(38);
    q.push(40);
    q.push(42);
    q.push(50);
    q.push(60);
    q.push(70);
    q.push(80);

    reverseInkGroups(q,3,q.size());

    while(!q.empty()){
        cout<<q.front()<<" ";
        q.pop();
    }

    return 0;
}