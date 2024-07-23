#include<iostream>
#include<vector>
using namespace std;

void findLastOccurence(vector<int> arr, int target, int &ansIndex){

    int s=0;
    int e=arr.size()-1;
    int mid = s+(e-s)/2;

    while(s<=e){

        if(arr[mid]==target){
            ansIndex=mid;
            s=mid+1;
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
    
    vector<int> arr = {20,20,20,50,60,70,80};
    int ansIndex=-1;
    int target=20;
    findLastOccurence(arr,target,ansIndex);

    cout<<ansIndex;


    return 0;
}