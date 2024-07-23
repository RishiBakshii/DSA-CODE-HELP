/*

Set:
• Sorted collection of unique elements.
• Elements are stored in sorted order, and duplicates are automatically
removed.
• Provides efficient insertion, deletion, and search operations

Member Functions:
• begin(): Returns an iterator pointing to the first element in the set.
• end(): Returns an iterator pointing to the past-the-end element in the set.
• empty(): Checks if the set is empty (i.e., whether its size is 0).
• size(): Returns the number of elements currently in the set.
• insert(const T& value): Inserts a new element into the set, maintaining the order and uniqueness of
elements.
• erase(const T& key) or erase(iterator position) or erase(iterator first, iterator last): Removes one or more
elements from the set specified by key or position.
• clear(): Removes all elements from the set, which are destroyed, and leaves it with a size of 0.
• find(const T& key): Returns an iterator to the element with the given key, or end() if the key is not found.
• count(const T& key): Returns the number of elements with the specified key (1 or 0, since std::set does
not allow duplicate keys)

*/

#include<iostream>
#include<set>
#include<unordered_set>
using namespace std;

int main(){
    



    return 0;
}