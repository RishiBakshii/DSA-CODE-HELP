#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>
using namespace std;

bool isPossibleSolution(vector<long long int>&arr,long long int mid,long long int m){

    long long int i=0;
    long long int n=arr.size();
    long long int bladeHeight = mid;

    while(i<n && m){

        long long int treeHeight = arr[i];

        if(treeHeight>bladeHeight){
            m-=treeHeight-bladeHeight;
        }

        i++;

    }

    return m<=0;

}

void findMaxHeight(vector<long long int>&arr, long long int m, long long int &ans){

    long long int s=0;
    // int e=accumulate(arr.begin(),arr.end(),0);
    long long int e = *max_element(arr.begin(),arr.end());


    while(s<=e){

        long long int mid = s+(e-s)/2;

        if(isPossibleSolution(arr,mid,m)){
            ans=mid;
            s=mid+1;
        }
        else{
            e=mid-1;
        }

    }

}

int main(){
    
    long long int ans=-1;
    vector<long long int> arr;
    long long int m;
    long long int n;

    cin>>n>>m;

    while(n--){
        long long int treeHeight;
        cin>>treeHeight;
        arr.push_back(treeHeight);
    }

    if(m>accumulate(arr.begin(),arr.end(),0)){
        ans=-1;
    }
    else{
        findMaxHeight(arr,m,ans);
    }

    cout<<"The anwer is "<<ans;

    return 0;
}