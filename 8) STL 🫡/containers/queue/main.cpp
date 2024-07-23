/*

Queue:
• Adaptor class that provides a First-In, First-Out (FIFO) data structure.
• Implemented using other containers (e.g., deque, list) as the underlying
storage.

Member Functions:
• empty(): Checks if the queue is empty (i.e., whether its size is 0).
• size(): Returns the number of elements in the queue.
• front(): Accesses the first element in the queue, which is the next element to be removed.
• back(): Accesses the last element in the queue, which is the most recently added element.
• push(const T& value): Adds an element to the end of the queue.
• pop(): Removes the first element from the queue.
• swap(queue& x): Swaps the contents of the queue with those of another queue of the
same type.

*/

#include<iostream>
#include<queue>
using namespace std;

int main(){
    
    // creation
    queue<int> q;

    return 0;
}