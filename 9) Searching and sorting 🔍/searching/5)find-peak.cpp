#include<iostream>
#include<vector>
using namespace std;

int findPeak(vector<int> &arr){

    int s=0;
    int e=arr.size()-1;
    int mid = s+(e-s)/2;

    while(s<=e){

        if(arr[mid]>arr[mid-1] && arr[mid]>arr[mid+1]){
            return mid;
        }
        else{
            if(arr[mid]<arr[mid+1]){
                s=mid+1;
            }
            else{
                e=mid-1;
            }
        }
        mid = s+(e-s)/2;

    }

    return -1;

}

int storeAndComputeApproch(vector<int> &arr){

    int s=0;
    int n=arr.size();
    int e=n-1;
    int mid = s+(e-s)/2;
    int ansIndex = -1;

    while(s<=e){

        if(arr[mid]<arr[mid+1]){
            s=mid+1;
        }
        else{
            ansIndex=mid;
            e=mid-1;
        }

        mid = s+(e-s)/2;
    }

    return ansIndex;

}

int main(){
    
    vector<int> arr = {2,7,11,15,25,14,10,6,4,1,50};
    // cout<<findPeak(arr);
    // hello world  DD
    cout<<storeAndComputeApproch(arr);

    return 0;
}