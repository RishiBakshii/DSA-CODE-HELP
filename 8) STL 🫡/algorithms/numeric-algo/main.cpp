/*

Numeric Algorithms:
• std::accumulate: Computes the sum of elements in a range.
• std::inner_product: Computes the inner product of two ranges.
• std::partial_sum: Computes the partial sums of a range.
• std::iota: Fills a range with incrementing values.

*/

#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>
using namespace std;

int main(){
    
    vector<int> arr(5);

    arr.push_back(10);
    arr.push_back(20);
    arr.push_back(30);
    arr.push_back(40);
    arr.push_back(50);

    // accumulater
    // int totalSum = accumulate(arr.begin(),arr.end(),0);
    // cout<<totalSum;

    // inner product
    // vector<int> arr1;
    // arr1.push_back(1);
    // arr1.push_back(2);
    // arr1.push_back(3);

    // vector<int> arr2;
    // arr2.push_back(3);
    // arr2.push_back(4);
    // arr2.push_back(5);

    // int ans =  inner_product(arr1.begin(),arr1.end(),arr2.begin(),0);
    // cout<<ans;

    // partial sum
    // vector<int> partialSumVect(5);

    // partial_sum(arr.begin(),arr.end(),partialSumVect.begin());

    // for(auto i:arr){
    //     cout<<i;
    // }

    // iota
    // vector<int> consecutiveValues(5);
    // iota(consecutiveValues.begin(),consecutiveValues.end(),250);

    // for(auto i:consecutiveValues){
    //      cout<<i<<" ";
    // }


    return 0;
}