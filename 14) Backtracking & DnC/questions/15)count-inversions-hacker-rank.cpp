#include<iostream>
#include<vector>
using namespace std;

// TC => O(nlogn)
// SC => O(n)

int countInversionM1(vector<int>&arr){

    int count=0;
    int n = arr.size();

    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(arr[i]>arr[j]) count++;
        }
    }

    return count;
}

long merge(vector<int>&arr,vector<int>&temp, int start, int mid, int end){

    int i = start;
    int j = mid+1;
    int k = start;

    long c = 0;

    while(i<=mid && j<=end){

        if(arr[i]<=arr[j]){
            temp[k++]=arr[i++];
        }
        
        // inverison count case;
        else {
            temp[k++]=arr[j++];
            c+=mid-i+1;
        }

    }

    while(i<=mid) temp[k++]=arr[i++];
    while(j<=mid) temp[k++]=arr[j++];

    while(start<=end){
        arr[start] = temp[start];
        start++;
    }

    return c;

}

long mergeSort(vector<int>&arr,vector<int>&temp,int s,int e){


    if(s>=e) return 0;
    int mid = s+(e-s)/2;

    long c = 0;

    c+=mergeSort(arr,temp,s,mid);
    c+=mergeSort(arr,temp,mid+1,e);
    c+=merge(arr,temp,s,mid,e);

    return c;

}

long countInvesionsM2(vector<int>&arr){

    long c = 0; // inversion counts
    vector<int> temp(arr.size(),0);

    c = mergeSort(arr,temp,0,arr.size()-1);
    
    return c;

}

int main(){

    vector<int> arr = {8,4,2,1};
    // cout<<countInversionM1(arr);

    cout<<countInvesionsM2(arr);

    return 0;
}