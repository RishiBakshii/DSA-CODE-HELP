/*

C++ Iterators

• An iterator is a pointer-like object representing an element's position in a container. It is used to iterate over elements in a container.
• Suppose we have a vector named nums of size 4. Then, begin() and end() are member functions that return iterators pointing to the beginning and end of the vector respectively.
• nums.begin() points to the first element in the vector i.e 0th index
• nums.begin() + i points to the element at the ith index.
• nums.end() points to one element past the final element in the vector


Iterator Operations

- *itr
- itr->m
- ++itr
- --itr
- itr + i
- itr1 == itr2
- itr1 != itr2
- itr = itr1


Why use Iterators ?

• Working with Algorithms: C++ has many ready-to-use algorithms like finding elements, sorting, and summing values. Iterators help you apply these algorithms to different types of data containers like arrays or lists.
• Saving Memory: Instead of loading a huge set of data all at once, iterators let you deal with one item at a time, which saves memory.
• Uniform Approach: Iterators allow you to interact with different kinds of data containers (like vectors or sets) in the same way. This makes your code more consistent and easier to manage.
• Simpler Code: By using iterators, a lot of the repetitive details of going through Be data are taken care of, making your code cleaner and easier to read.

*/

#include<iostream>
#include<vector>
using namespace std;

int main(){
    
    vector<int> arr;
    arr.push_back(10);
    arr.push_back(20);
    arr.push_back(30);

    // traverse using iterator
    // create iterator
    vector<int>::iterator it = arr.begin();

    while(it != arr.end()){
        cout<<*it++<<" ";
    }

    return 0;
}