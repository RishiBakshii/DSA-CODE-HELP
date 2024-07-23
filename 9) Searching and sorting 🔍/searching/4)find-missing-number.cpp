#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int findMissingNumberUsingBinarySearch(vector<int> arr , int &ans){

    int s=0;
    int e=arr.size()-1;
    int mid = s+(e-s)/2;

    while(s<=e){

        if(arr[mid]!=mid){
            ans=mid;
            e=mid-1;
        }
        else{
            s=mid+1;
        }

        mid = s+(e-s)/2;
    }

}

int main(){

    vector<int> arr = {0,1};
    sort(arr.begin(),arr.end());
    int ans = 24;
    cout<<findMissingNumberUsingBinarySearch(arr,ans); 
    return 0;
}