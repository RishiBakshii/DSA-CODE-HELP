/*

Deque:
• Double-ended queue.
• Similar to vectors but allows efficient insertion and removal at both ends.
• Suitable when elements need to be inserted or removed frequently from the
front or back.

Member Functions:
• begin(): Returns an iterator pointing to the first element in the deque.
• end(): Returns an iterator pointing to the past-the-end element in the deque.
• size(): Returns the number of elements currently in the deque.
• empty(): Checks if the deque is empty (i.e., whether its size is 0).
• front(): Accesses the first element in the deque.
• back(): Accesses the last element in the deque.
• operator[](size_type n): Accesses the element at the specified index without bounds checking.
• at(size_type n): Accesses the element at the specified index with bounds checking.
• push_back(const T& value): Adds an element to the end of the deque.
• pop_back(): Removes the last element from the deque. pop_front(): Removes the first element from the deque.
• push_front(const T& value): Adds an element to the beginning of the deque.
• insert(iterator position, const T& value): Inserts a new element before the specified position in the deque.
• erase(iterator position) or erase(iterator first, iterator last): Removes one or more elements from the deque starting at the specified position.
• clear(): Removes all elements from the deque, which are destroyed, and leaves it with a size of 0.
• swap(deque& x): Swaps the contents of the deque with those of another deque of the same type, including their sizes.

*/

#include<iostream>
#include<deque>
using namespace std;

int main(){


    


    return 0;
}