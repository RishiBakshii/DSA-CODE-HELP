#include<iostream>
#include<vector>
using namespace std;

// TC => O(nlogn);
// gap method is the best method for inPlaceMerge sort

void inPlaceMerge(vector<int>&arr,int s,int e){

    // getting the total length
    int totalLength = e-s+1;

    // calculating gap
    // it is equivalent to
    // gap = ceil(totalLength/2)
    // but instead of ceil we are adding this (totalLength%2) in the end
    int gap = (totalLength/2) + (totalLength%2); // ceil

    while(gap>0){

        int i=s;
        int j=i+gap;

        while(j<=e){
            if(arr[i]>arr[j]) swap(arr[i],arr[j]);
            i++;
            j++;
        }

        // after the iteration ends
        // updating the gap
        // this condition  gap<=1 ? 0 is here because
        // if the gap was 1 for the previous iteration
        // then because of ceil the gap will always come 1 by which
        // we will be stuck in infinite loop
        // so we are making a conidtion that if gap == 1 then
        // make it 0 this time and this will cause the loop to end
        gap = gap<=1 ? 0 : (gap/2) + (gap%2);
    }

}

void mergeSort(vector<int>&arr,int s,int e){

    // base case
    if(s>=e) return;

    // calculating mid
    int mid = s+(e-s)/2;

    // left array
    mergeSort(arr,s,mid);
    // right array
    mergeSort(arr,mid+1,e);
    // merge
    inPlaceMerge(arr,s,e);

}

int main(){
    
    vector<int> arr = {10,30,20,50,40,70,60,90,80,100};
    mergeSort(arr,0,arr.size()-1);

    for(auto i:arr) cout<<i<<" ";

    return 0;
}