#include<iostream>
#include<vector>
using namespace std;

int exponentialSearch(vector<int>&arr, int x){

    if(arr[0]==x){
        return 0;
    }

    int i=1;
    
    while(i<arr.size() && arr[i]<=x){

        i*=2;  // i=i*2 // i>>1

    }

    return i;

}

int binarySearch(vector<int>&arr, int s, int e, int x){


    while(s<=e){

        int mid = s+(e-s)/2;

        if(arr[mid]==x){
            return mid;
        }
        else if(arr[mid]<x){
            s=mid+1;
        }
        else{
            e=mid-1;
        }

    }

    return -1;


}

int main(){
    
    vector<int> arr = {3,4,5,6,11,13,14,15,56,70};
    int n = arr.size();
    int x=13;
    int i = exponentialSearch(arr,x);
    int s=i/2;
    int e=min(i,n);

    cout<<"start "<<s<<endl;
    cout<<"end "<<e<<endl;

    int ans = binarySearch(arr,s,e,x);
    cout<<"the answer index is "<<ans;

    return 0;
}