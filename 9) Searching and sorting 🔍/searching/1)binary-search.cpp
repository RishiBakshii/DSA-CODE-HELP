#include<iostream>
#include<vector>
using namespace std;

int binarySearch(vector<int> arr , int target){

    int s = 0;
    int e = arr.size()-1;
    //int mid = (s+e)/2;  // this formula can cause overflow issues in int

    // so this is a failsafe formula
    int mid = s + (e-s)/2;

    while(s<=e){

        if(arr[mid]==target){
            return mid;
        }

        else if(arr[mid]<target){
            s=mid+1;
        }

        else{
            e=mid-1;
        }

        mid=(s+e)/2;

    }

    return -1;

}

int main(){
    
    vector<int> arr = {10,20,30,40,50};
    cout<<binarySearch(arr,20);

    return 0;
}