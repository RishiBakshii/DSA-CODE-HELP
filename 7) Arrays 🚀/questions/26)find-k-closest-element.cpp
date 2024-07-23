#include<iostream>
#include<vector>
using namespace std;

void printArray(vector<int>&arr){

    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }
}

vector<int> twoPointerApproach(vector<int>&arr, int x, int k){

    int l=0;
    int h=arr.size()-1;

    while(h-l>=k){

        int lowDiff=x-arr[l];
        int highDiff=arr[h]-x;

        if(lowDiff>highDiff){
            l++;
        }
        else{
            h--;
        }
    }

    return vector<int>(arr.begin()+l,arr.begin()+h+1);

}

int findLowerBound(vector<int>&arr, int target){

    int ans=-1;
    int s=0;
    int e=arr.size()-1;

    while(s<=e){

        int mid = s+(e-s)/2;

        if(arr[mid]==target){
            ans=mid;
            break;
        }
        else if(arr[mid]<target){
            ans=mid;
            s=mid+1;
        }
        else{
            ans=mid;
            e=mid-1;
        }

    }

    return ans;
}

vector<int> bsAndTwoPointerApproch(vector<int>&arr, int x, int k){
    int h=findLowerBound(arr,x);
    int l=h-1;

    while(k--){
        int lDiff=x-arr[l];
        int hDiff=arr[h]-x;

        if(l<0){
            h++;
        }
        else if(h==arr.size()-1){
            l--;
        }
        else if(lDiff>hDiff){
            h++;
        }
        else{
            l--;
        }
    }

    return vector<int>(arr.begin()+l+1,arr.begin()+h);
}

int main(){

    // vector<int> arr = {12,16,22,30,35,39,42,45,48,50,53,55,56};
    vector<int> arr = {3,5,8,10};
    int k=4;
    int x=35;
    // vector<int> ans =twoPointerApproach(arr,x,k);
    vector<int> ans = bsAndTwoPointerApproch(arr,x,k);
    printArray(ans);


    
    return 0;
}