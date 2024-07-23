#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool canFlowersBloomInXDays(vector<int> arr,int m, int k, int days){

    int count=0;

    for(int i=0;i<arr.size();i++){

        if(arr[i]<=days){
            // the flower is bloomed
            count++;
        }

        if(count==k){
            // resetting the count 
            // and marking that one bouguets is created 
            count=0;
            m--;

            if(m==0){
                break;
            }
        }

        if(arr[i]>days){
            count=0;
        }

    }

    return m==0;

}

void findMinDays(vector<int> &arr, int m, int k,int &ans){

    if(k*m>arr.size()){
        ans=-1;
        return;
    }

    int s = *min_element(arr.begin(),arr.end());
    int e = *max_element(arr.begin(),arr.end());
    int mid = s+(e-s)/2;

    while(s<=e){

        if(canFlowersBloomInXDays(arr,m,k,mid)){
            ans=mid;
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
    vector<int> bloomDays = {7,7,7,7,12,7,7};
    findMinDays(bloomDays,2,3,ans);
    cout<<ans;
    
    return 0;
}