#include <iostream>
#include<vector>
using namespace std;

double findMaxAverage(vector<int> &nums, int k){

    int i = 0;
    int j = k - 1;
    int sum = 0;
    int maxSum = 0;

    // first window sum (initial)
    for (int y = 0; y <= j; y++){
        
        sum += nums[y];
    
    }
    
    maxSum = sum;

    // to handle the cases where k==n
    j++;
    // if nums=[1,2,3,4], n=4 and k=4, so j will be at 4 right?, then doing j++ at
    // this point will prevent the loop to run at the first place
    while (j < nums.size())
    {
        sum = sum - nums[i++];
        sum = sum + nums[j++];
        maxSum = max(maxSum, sum);
    }

    double maxAvg = maxSum / (double)k;
    return maxAvg;
}

int main(){
    
    return 0;
}
