/*

Iterators and Iterating Algorithms:
• std::for_each: Applies a function to each element in a range. std::find: Searches for a specific element in a
range.
• std::find_if: Searches for the first element that satisfies a given predicate.
• std::count: Counts the occurrences of a value in a range.
• std::count_if: Counts the elements that satisfy a given predicate.
• std::sort: Sorts the elements in a range in ascending order.
• std::reverse: Reverses the order of elements in a range.
• std::rotate: Rotates elements in a range.
• std::unique: Removes duplicate elements from a sorted range.
• std::partition: Divides elements in a range into two groups based on a predicate.

*/


#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

void printDouble(int a){
    cout<<2*a;
}

bool checkEven (int a){
    return a%2==0;
}

int main(){

    vector<int> arr(5);

    arr[0]=10;
    arr[1]=20;
    arr[2]=30;
    arr[3]=40;
    arr[4]=50;

    // for each
    // for_each(arr.begin(),arr.end(),printDouble);

    // find
    // vector<int>::iterator it = find(arr.begin(),arr.end(),20);
    // cout<<*(it);

    // find_if
    // auto it = find_if(arr.begin(),arr.end(),checkEven);
    // cout<<*it;

    // count
    // int ans = count(arr.begin(),arr.end(),10);
    // cout<<ans;

    // count_if
    // int ans  = count_if(arr.begin(),arr.end(),checkEven);
    // cout<<ans;

    // sort
    // sort(arr.begin(),arr.end());

    // for(auto i:arr){
    //     cout<<i;
    // }

    // reverse
    // reverse(arr.begin(),arr.end());

    // for(auto i:arr){
    //     cout<<i;
    // }

    // rotate
    // rotate(arr.begin(),arr.begin()+3,arr.end());

    // for(auto i:arr){
    //      cout<<i;
    // }

    // unique
    // auto it = unique(arr.begin(),arr.end());
    // it ke pehle saare unique elements hain
    // and it ke baad saare duplicate elements hain

    // arr.erase(it,arr.end());

    // for(auto i:arr){
    //      cout<<i;
    // }


    // partition
    


    return 0;   
}