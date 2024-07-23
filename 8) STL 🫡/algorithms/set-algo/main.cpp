/*

Set Algorithm:
• std::set_union: Computes the union of two sorted ranges.
• std::set_intersection: Computes the intersection of two sorted ranges.
• std::set_difference: Computes the difference between two sorted ranges.
• std::set_symmetric_difference: Computes the symmetric difference of two
sorted ranges.

*/

#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main(){
    
    vector<int> first;
    first.push_back(1);
    first.push_back(2);
    first.push_back(3);
    first.push_back(4);
    
    vector<int> second;
    second.push_back(3);
    second.push_back(4);
    second.push_back(5);
    second.push_back(6);

    vector<int> result;
    
    // union
    // set_union(first.begin(),first.end(),second.begin(),second.end(),inserter(result,result.begin()));

    // for(int i:result){
    //     cout<<i;
    // }

    // intersection
    // set_intersection(first.begin(),first.end(),second.begin(),second.end(),inserter(result,result.begin()));

    // for(int i:result){
    //     cout<<i;
    // }

    // difference
    // set_difference(first.begin(),first.end(),second.begin(),second.end(),inserter(result,result.begin()));

    // for(int i:result){
    //     cout<<i;
    // }

    // difference
    set_symmetric_difference(first.begin(),first.end(),second.begin(),second.end(),inserter(result,result.begin()));

    for(int i:result){
        cout<<i;
    }

    return 0;
}