#include<iostream>
#include<vector>
using namespace std;

void findFirstOccurence(vector<int> arr, int target, int &ansIndex){

    int s=0;
    int e=arr.size()-1;
    int mid = s + (e-s)/2;

    while(s<=e){

        if(arr[mid]==target){
            // ans found -> may or may not be first occurence
            // store and compute
            ansIndex = mid;

            // kyuki first occurence ki baat hori h
            // toh we should go left
            // left me jaao
            e=mid-1;
        }

        else if(arr[mid]>target){
            e=mid-1;
        }

        else if(arr[mid]<target){
            s=mid+1;
        }
        
        mid = s+(e-s)/2;

    }

}


int main(){
    
    vector<int> arr = {5,10,20,20,20,20,20,20,20,30,40,50,60};
    int target = 20;
    int ansIndex=-1;
    findFirstOccurence(arr,target,ansIndex);
    cout<<ansIndex;

    return 0;
}