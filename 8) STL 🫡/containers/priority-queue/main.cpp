/*

Priority queue:
• Adaptor class that provides a priority queue (heap).
• Elements are stored in a way that allows the retrieval of the highest-priority
element efficiently.

Member Functions:
• empty(): Checks if the priority queue is empty (i.e., whether its size is 0).
• size(): Returns the number of elements currently in the priority queue.
• top(): Accesses the element at the top of the priority queue, which is the largest (or highest
priority) element, depending on the comparator used.
• push(const T& value): Adds an element to the priority queue and reorders it to maintain the
heap property.
• pop(): Removes the top element from the priority queue, which is the largest (or highest
priority) element, and reorders the remaining elements to maintain the heap property.
• swap(priority_queue& x): Swaps the contents of the priority queue with those of another
priority queue of the same type, including their underlying containers and comparators.

*/

#include<iostream>  
#include<queue>
using namespace std;

int main(){

    // creation
    // it creates a max heap i.e -> maximum value -> highest priority
    priority_queue<int> pq;

    pq.push(20);
    pq.push(30);
    pq.push(40);
    pq.push(10);

    cout<<pq.top();

    // min-heap -> minimum value -> highest priority
    priority_queue<int,vector<int>,greater<int>> pq2;
    
        
    return 0;
}