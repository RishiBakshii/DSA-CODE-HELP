/*

Heap Algorithm:
• std::make_heap: Converts a range into a max-heap.
• std::push_heap: Inserts an element into a max-heap.
• std::pop_heap: Removes the largest element from a max-heap.
• std::sort_heap: Sorts a range that represents a max-heap.

*/

#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main(){
    
    vector<int> arr;
    arr.push_back(22);
    arr.push_back(11);
    arr.push_back(55);
    arr.push_back(66);
    arr.push_back(77);

    // it creates a max-heap
    make_heap(arr.begin(),arr.end());

    for(int a:arr){
        cout<<a<<" ";
    }

    cout<<endl;

    // insertion
    arr.push_back(99);
    push_heap(arr.begin(),arr.end());

    for(int a:arr){
        cout<<a<<" ";
    }

    cout<<endl;

    // deletion
        // this method sends the largest element to the end
        pop_heap(arr.begin(),arr.end());
        // and by using this we then remove the last most element
        arr.pop_back();

    for(int a:arr){
        cout<<a<<" ";
    }

    cout<<endl;
    
    // sort
    sort_heap(arr.begin(),arr.end());
    for(int a:arr){
        cout<<a<<" ";
    }


    return 0;
}