/*

Vector :
• Dynamic array that can grow or shrink in size.
• Allows fast random access to elements.
• Insertion and removal of elements at the end is efficient.
• Suitable for most scenarios when elements need to be stored in a linear
sequence.

Member Functions:
• begin(): Returns an iterator pointing to the first element in the vector.
• end(): Returns an iterator pointing to the position just after the last element in the vector.
• size(): Returns the number of elements in the vector.
• empty(): Checks if the vector is empty (i.e., whether its size is 0).
• capacity(): Returns the number of elements that the vector can hold before needing to allocate more space.
• reserve(size_type n): Requests that the vector capacity be increased to at least n elements, potentially reducing the number of reallocations.
• max_size(): Returns the maximum number of elements that the vector can hold due to system or library limitations.
• front(): Accesses the first element in the vector.
• back(): Accesses the last element in the vector.
• operator[](size_type n): Accesses the element at the specified index without bounds checking.
• at(size_type n): Accesses the element at the specified index with bounds checking.
• push_back(const T& value): Adds an element to the end of the vector.
• pop_back(): Removes the last element from the vector.
• insert(iterator position, const T& value): Inserts a new element before the specified position in the vector.
• erase(iterator position) or erase(iterator first, iterator last): Removes one or more elements from the vector starting at the specified position.
• clear(): Removes all elements from the vector, which are destroyed, and leaves it with a size of 0.
• swap(vector& x): Swaps the contents of the vector with those of another vector of the same type, including their sizes and capacities.

*/

#include<iostream>
#include<vector>
using namespace std;

int main(){

    // creation
    vector<int> marks;

    marks.push_back(10);
    marks.push_back(20);
    marks.push_back(30);
    marks.push_back(40);

    // cout<< *(marks.begin());

    // cout<< marks.size();
    
    // marks.pop_back();

    // cout<< marks.size();

    // vector<int> miles(10);

    // vector<int> distances(15,0);


    // traversing the vector using iterator

    // creating an iterator
    vector<int>::iterator it = marks.begin();
    
    while(it!=marks.end()){
        cout<<*(it++)<<" ";
    }

    // creating a 2d vector
    vector<vector<int>> vector2d(4,vector<int>(4,0));

    // creating a 2d vector with different column counts
    vector<vector<int>> arr(4);

    arr[0] = vector<int>(4);
    arr[1] = vector<int>(2);
    arr[2] = vector<int>(5);
    arr[3] = vector<int>(3);

    int totalRows=arr.size();
    // int totalColumns = arr[i].size()

    return 0;
}