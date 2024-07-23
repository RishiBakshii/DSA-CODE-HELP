#include<iostream>
#include<vector>
using namespace std;

int findPivot(vector<int> &arr){


    int n=arr.size();

    int s=0;
    int e=n-1;
    int mid = s+(e-s)/2;

    while(s<=e){

        // this condition hanldes the case of single element
        // single element ke case mein humne ussehi pivot man liya h!
        if(s==e){
            return s;
        }

        // determining if i am at line a or ab
        if(arr[mid]<arr[s]){
            // line b
            e=mid-1;
        }
        else{
            // line a
            if(arr[mid]>arr[mid+1]){
                // this is the pivot index
                return mid;
            }
            else{
                s=mid+1;
            }
        }

        mid = s+(e-s)/2;


    }
}

int binarySearch(vector<int> &arr, int s, int e, int target){

    int mid = s+(e-s)/2;

    while(s<=e){

        if(arr[mid]==target){
            return mid;
        }
        else if(arr[mid]>target){
            e=mid-1;
        }
        else{
            s=mid+1;
        }

        mid = s+(e-s)/2;
    }

}

int main(){

    int ans=-1;

    vector<int> arr = {4,5,6,7,0,1,2};

    int pivotIndex = findPivot(arr);
    cout<<"PivotIndex "<<pivotIndex<<endl;

    int target=4;

    if(target>=arr[0] && target<=arr[pivotIndex]){
        ans=binarySearch(arr,0,pivotIndex,target);
    }
    else if(target>=arr[pivotIndex+1] && target<=arr[arr.size()-1]){
        ans=binarySearch(arr,pivotIndex+1,arr.size()-1,target);  
    }

    cout<<target<<" lies at index "<<ans;
    

    return 0;
}