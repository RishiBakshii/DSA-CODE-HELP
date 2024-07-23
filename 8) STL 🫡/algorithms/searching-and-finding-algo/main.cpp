/*

Searching and Finding Algorithm:
• std::binary_search: Checks if a value exists in a sorted range.
• std::lower_bound: Finds the first element greater or equal to a value in a
sorted range.
• std::upper_bound: Finds the first element greater than a value in a sorted
range.
• std::equal_range: Finds a range of elements equal to a value in a sorted
range.

*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    
    vector<int> arr;
    arr.push_back(10);
    arr.push_back(20);
    arr.push_back(30);
    arr.push_back(40);
    arr.push_back(50);

    // binary search
    // bool isExists = binary_search(arr.begin(),arr.end(),20);
    // cout<<isExists;

    // lower bound (if element is not present , returns an element just bigger than that, if present returns that element)
    // auto it = lower_bound(arr.begin(),arr.end(),35);
    // cout<<*it;

    // upper bound (if elemenet is present or not it always returns  a bigger element than that)
    auto it = upper_bound(arr.begin(),arr.end(),35);
    cout<<*it;



    return 0;
}