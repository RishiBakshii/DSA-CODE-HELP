#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;

/*
If all the elements were positive in the array then we would have returned the whole sum of the array as that would be maximum subarray i.e the array itself

but that is not the case we have negative elements also


M1 (Navie Brute Force)
find all subarray then find the maximum of them

M2 (D&C)

*/

// TC=> O(nlogn)

int maximumSubArraySum(vector<int>&nums,int s,int e){

    // base case
    if(s==e) return nums[s];
    
    int mid = s+(e-s)/2;

    int maxLeftSum = maximumSubArraySum(nums,s,mid);
    int maxRightSum = maximumSubArraySum(nums,mid+1,e);

    // Max cross border sum

    int maxleftCrossBorderSum=INT_MIN;
    int maxrightCrossBorderSum=INT_MIN;


    int leftCrossBorderSum=0;
    for(int i=mid;i>=s;i--){
        leftCrossBorderSum+=nums[i];
        if(leftCrossBorderSum>maxleftCrossBorderSum) maxleftCrossBorderSum=leftCrossBorderSum;
    }

    int rightCrossBorderSum=0;
    for(int i=mid+1;i<=e;i++){
        rightCrossBorderSum+=nums[i];
        if(rightCrossBorderSum>maxrightCrossBorderSum) maxrightCrossBorderSum=rightCrossBorderSum;
    }

    int crossBorderSum = maxleftCrossBorderSum + maxrightCrossBorderSum;

    // max of all three
    return max(crossBorderSum,max(maxLeftSum,maxRightSum));



}

int main(){

    vector<int> nums = {-1,-2,-3,0};
    cout<<maximumSubArraySum(nums,0,nums.size()-1);

    return 0;
}  