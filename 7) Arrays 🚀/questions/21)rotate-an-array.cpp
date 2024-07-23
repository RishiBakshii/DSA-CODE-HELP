#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void rotateArray(vector<int> &arr, int k){

    // 1) reverse all
    reverse(arr.begin(),arr.end());

    // 2) reverse first k
    reverse(arr.begin(),arr.begin()+k);

    // 3) reverse k -> n
    reverse(arr.begin()+k,arr.end());

}

int main(){

    vector<int> arr = {1,2,3,4,5,6,7};
    int k=3;

    rotateArray(arr,3);

    for(auto i:arr) cout<<i<<" ";
    
    return 0;
}