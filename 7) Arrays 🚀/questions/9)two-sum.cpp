#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void print(vector<int> arr,int n){

    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }

}

// O(n^2)
vector<int> findTwoSumPair(vector<int> &arr, int n, int target){

    vector<int> ans;

    for(int i=0;i<n-1;i++){

        for(int j=i+1;j<n;j++){

            if(arr[i]+arr[j]==target){
                ans.push_back(i);
                ans.push_back(j);
                break;
            }

        }

    }

    return ans;

}

// Optimal solution is to use
// two pointer approch after sorting the array
// for O(nlogn)
vector<int> findTwoSumPairTwoPointerApproch(vector<int> &arr , int n , int target){

    sort(arr.begin(),arr.end());
    
    cout<<"sorted array"<<endl;
    print(arr,n);
    cout<<endl;

    vector<int> ans;

    int l=0;
    int h=n-1;

    while(l<h){

        int csum = arr[l]+arr[h];

        if(csum==target){
            ans.push_back(l);
            ans.push_back(h);
            break;
        }
        else if(csum>target){
            h--;
        }
        else{
            l++;
        }

    }

    return ans;


}

int main(){
    
    vector<int> arr = {3,2,3};
    int size = arr.size();

    // vector<int> result = findTwoSumPair(arr,size,6);
    vector<int> result = findTwoSumPairTwoPointerApproch(arr,size,6);

    print(result,result.size());

    return 0;
}