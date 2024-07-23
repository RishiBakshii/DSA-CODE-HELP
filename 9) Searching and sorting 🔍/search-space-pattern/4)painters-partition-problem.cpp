#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>
using namespace std;

bool isPainterAllocationPossible(int limitForEachPainter, int k, vector<int>&arr, int &ans){

    int painter = 1;
    int sum=0;
    int maxSum=0;

    int n = arr.size();


    for(int i=0;i<n;i++){

        if(sum+arr[i]>limitForEachPainter){

            if(painter<k){
                maxSum = max(maxSum,sum);
                painter++; 
                sum=arr[i];
            }
            else{
                return false;
            }
        }
        else{
            sum+=arr[i];
        }

    }

    maxSum = max(maxSum, sum);

    if(painter==k){
        ans = maxSum;
        return true;
    }
    else{
        return false;
    }

}

void findMinTime(vector<int>&arr, int k, int &ans){

    // search space
    int e=accumulate(arr.begin(),arr.end(),0);
    int s=*max_element(arr.begin(),arr.end());


    while(s<=e){

        int mid = s+(e-s)/2;

        if(isPainterAllocationPossible(mid,k,arr,ans)){
            s=mid+1;
        }
        else{
            e=mid-1;
        }

    }

}


int main(){
    
    int ans = 0;
    vector<int> arr = {10,20,30,40};
    int k= 2;

    findMinTime(arr,k,ans);

    cout<<"The answer is "<<ans;

    return 0;
}