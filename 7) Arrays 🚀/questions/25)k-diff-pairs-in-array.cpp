#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;

set<pair<int,int>> findPairs(vector<int> &arr, int k){

    // set of pairs so store distinct pairs
    set<pair<int,int>> ans;

    // sorting the array
    sort(arr.begin(),arr.end());

    int i=0;
    int j=1;

    while(j<arr.size()){

        // calculating the difference
        int diff = arr[j]-arr[i];
        if(diff==k){
            cout<<"Pair : "<<arr[i]<<" "<<arr[j]<<endl;
            ans.insert({arr[i],arr[j]});
            i++;
            j++;
        }
        else if(diff>k){
            i++;
        }
        else if(diff<k){
            j++;
        }
        if(i==j){
            // when i==j it forwards the j avoiding errors when k=0
            j++;
        }

    }

    return ans;
}


bool binarySearch(vector<int>&arr, int s, int target){

    int e=arr.size()-1;

    while(s<=e){

        int mid = s+(e-s)/2;

        if(arr[mid]==target){
            return true;
        }
        else if(arr[mid]<target){
            s=mid+1;
        }
        else{
            e=mid-1;
        }

    }

    return false;
}

set<pair<int,int>> findPairs2(vector<int>&arr, int k){


    sort(arr.begin(),arr.end());
    set<pair<int,int>> ans;

    for(int i=0;i<arr.size();i++){

        if(binarySearch(arr,i+1,arr[i]+k)){
            ans.insert({arr[i],arr[i]+k});
        }

    }

    return ans;

}

int main(){

    vector<int> arr = {1,3,1,5,4};
    int k=2;
    set<pair<int,int>> ans= findPairs2(arr,k);
    cout<<ans.size();
    
    return 0;
}