#include<iostream>
#include<vector>
using namespace std;

/*
In this question the solving mindset is

hum current ghar ko loot ke bhi dhek rahe hain
and current ghar ko chod ke bhi dhek rahe hain

dono hi rob amounts mein se, jonsa max hain
usko return kra rahe hain
*/

// TC => O(n^2)
// whenever we are making two calls in every solution
// that means it is a exponential time complexity
// i.e O(n^2);


// SC => O(n)

int robHelper(vector<int>&nums, int i){


    if(i>=nums.size()) return 0;

    int robAmount1 = nums[i] + robHelper(nums,i+2);
    int robAmount2 = 0 + robHelper(nums,i+1);

    return max(robAmount1,robAmount2);

}

int main(){
    
    vector<int> houses = {2,1,1,2};
    cout<<robHelper(houses,0);

    return 0;
}