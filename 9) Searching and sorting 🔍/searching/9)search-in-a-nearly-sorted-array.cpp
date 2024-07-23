#include<iostream>
#include<vector>
using namespace std;

int searchInNearlySorted(vector<int> &arr, int target){

    int s=0;
    int n=arr.size();
    int e=n-1;
    int mid = s+(e-s)/2;

    while(s<=e){

        // cout<<"mid values"<<mid;

        if(arr[mid]==target){
            return mid;
        }
        if(arr[mid-1]==target){
            return mid-1;
        }
        if(arr[mid+1]==target){
            return mid+1;
        }
        if(arr[mid]<target){
            s=mid+2;
        }
        else{
            e=mid-2;
        }

        mid = s+(e-s)/2;

    }

    return -1;


}


int main(){
    
    vector<int> arr = {10,3,40,20,50,80,70};
    int target = 70;
    cout<<searchInNearlySorted(arr,target);

    return 0;
}