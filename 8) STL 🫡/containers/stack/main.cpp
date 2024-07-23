/*

Stack:
• Adaptor class that provides a Last-In, First-Out (LIFO) data structure.
• Implemented using other containers (e.g., vector, deque, list) as the
underlying storage.

Member Functions:
• empty(): Checks if the stack is empty (i.e., whether its size is 0).
• size(): Returns the number of elements in the stack.
• top(): Accesses the top element of the stack, which is the most recently added element.
• push(const T& value): Adds an element to the top of the stack.
• pop(): Removes the top element from the stack.
• swap(stack& x): Swaps the contents of the stack with those of another stack
of the same type.

*/


#include<iostream>
#include<stack>
using namespace std;

int main(){

    // creation
    stack<int> st;
    
    return 0;
}