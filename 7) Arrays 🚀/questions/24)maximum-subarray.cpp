#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;

int navie(vector<int> &arr){

    int ans = INT_MIN;

    int i=0;
    int j=0;
    int n = arr.size();

    int sum = 0 ;

    while(i<n){

        if(j==n-1){
            i++;
            sum=0;
        }

        sum+=arr[j];
        ans=max(sum,ans);
        j++;
        
    }

    return ans;

}

int kadenceAlgo(vector<int> arr){

    int ans = INT_MIN;
    int sum = 0;

    for(int i=0;i<arr.size();i++){
        sum+=arr[i];
        ans = max(ans,sum);
        if(sum<0) sum=0;
    }

    return ans;

}

int main(){
    
    vector<int> arr = {-2,1,-3,4,-1,2,1,-5,4};
    cout<<kadenceAlgo(arr);

    return 0;
}