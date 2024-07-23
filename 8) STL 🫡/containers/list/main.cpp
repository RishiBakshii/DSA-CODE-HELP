/*

List :
• Doubly-linked list.
• Allows fast insertions and removals anywhere in the list.
• No random access like vectors

Member Functions:
• begin(): Returns an iterator pointing to the first element in the list.
• end(): Returns an iterator pointing to the past-the-end element in the list.
• size(): Returns the number of elements in the list.
• empty(): Checks if the list is empty (i.e., whether its size is 0).
• front(): Accesses the first element in the list.
• back(): Accesses the last element in the list.
• push_back(const T& value): Adds an element to the end of the list.
• pop_back(): Removes the last element from the list.
• insert(iterator position, const T& value): Inserts a new element before the specified position in the list.
• erase(iterator position) or erase(iterator first, iterator last): Removes one or more elements from the list starting at the specified position.
• clear(): Removes all elements from the list, which are destroyed, and leaves it with a size of 0.
• swap(list& x): Swaps the contents of the list with those of another list of the same type, including their sizes.
• pop_front(): Removes the first element from the list.
• push_front(const T& value): Adds an element to the beginning of the list.
• remove(const T& value): Removes all elements from the list that are equal to the specified value.

*/

#include<iostream>
#include<list>
using namespace std;

int main(){
    
    // creation
    list<int> myList;

    // insertion
    myList.push_back(10);
    myList.push_back(20);
    myList.push_back(30);
    myList.push_back(40);

    myList.push_front(100);

    // deletion
    myList.pop_back();
    myList.pop_front();

    // knowing the size
    myList.size();

    // clearing
    myList.clear();

    // checking if list empty or not
    myList.empty();

    // interating on a list
    list<int>::iterator it = myList.begin();

    while(it != myList.end()){
        cout<<*(it++) << "";
    }

    return 0;
}