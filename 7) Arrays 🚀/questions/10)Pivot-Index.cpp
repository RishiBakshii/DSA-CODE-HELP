#include<iostream>
#include<vector>
using namespace std;

int findPivotIndexByBruteForce(vector<int> &arr,int n){

    int leftSum=0;
    int rightSum;

    for(int i=0;i<n-1;i++){

        cout<<"for ith "<<i<<endl;
        cout<<"left Sum"<<leftSum<<endl;
        cout<<"right Sum"<<rightSum<<endl<<endl;

        // left loop
        for(int j=i-1;j>=0;j--){
            leftSum+=arr[j];
        }

        // right loop
        for(int k=i+1;k<n;k++){
            if(k==n-1){
                rightSum=0;
            }
            rightSum+=arr[k];
        }

        // condition to match
        if(leftSum==rightSum){
            return i;
        }

    }

    return -1;

    cout<<leftSum<<" "<<rightSum<<endl;

}


int prefixSumApproch(vector<int> &arr){

    int size = arr.size();

    vector<int> lsum(size,0);
    vector<int> rsum(size,0);

    // lsum
    for(int i=1;i<size;i++){
        lsum[i]=lsum[i-1]+arr[i-1];
    }

    // rsum
    for(int j=size-2;j>=0;j--){
        rsum[j]=rsum[j+1]+arr[j+1];
    }

    // check
    for(int k=0;k<size;k++){
        if(lsum[k]==rsum[k]){
            return k;
        }
    }

    return -1;

}

int main(){
    

    vector<int> arr={1,7,3,6,5,6};
    int size = arr.size();

    // cout<<findPivotIndexByBruteForce(arr,size);
    cout<<prefixSumApproch(arr);

    return 0;
}