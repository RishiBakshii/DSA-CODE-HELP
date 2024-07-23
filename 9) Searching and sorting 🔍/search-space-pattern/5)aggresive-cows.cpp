#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool allocationPossible(vector<int>&arr,int k,int mid){

    // we will placing the first cow at 0th position
    // that is why starting the i from 1
    int i=1;

    // as the first cow will be placed at 0th position
    // so prevCowIndexPosition will be at 0
    // so that while placing other cow we will be able to refer to where previous cow is placed to maintain the minimum difference
    int prevCowPosition = 0;

    // as the first cow is placed already so k--;
    k--;

    // getting the size of array for looping
    int n = arr.size();

    // loop will stop on two conditions
    // 1) if we traverse the whole array(stalls)
    // 2) Or if we were able to place all cows with a minimum of "mid" distance
    while(i<n && k){

        // checking if currentCow will be having the minimum distance from preivous cow that we have placed
        if((arr[i]-arr[prevCowPosition])>=mid){

            // if the minimum distance condition gets fulfilled then we will place the cow i.e k--;
            // and the cow that we have just placed, will be the prevCowPosition for another cow i.e  prevCowPosition=i;
            prevCowPosition=i;
            k--;
        }

        i++;
    };

    // only returns true if all the cows were placed
    return k==0;

}

void findMinDistance(vector<int>&arr,int k,int&ans){

    int s=1; // the lower bound of searchSpace

    // the upperBound of searchSpace
    // e = maxElement-minElement as because the distance between the stalls that are most far from each other 
    // will be the peak distance of how far we can place cows from each other
    int e=*max_element(arr.begin(),arr.end())-*min_element(arr.begin(),arr.end());

    while(s<=e){

        int mid = s+(e-s)/2;

        if(allocationPossible(arr,k,mid)){
            // if the allocation was possible with mid distance
            // store and compute
            ans=mid;  // storing the distance with which allocation was possible
            s=mid+1;  // further trying to acheive more distance , so that we can get the minimum distance between cows maximised
        }
        else{
            // if the allocation was not possible
            // that means the distance was a lot
            // trying with lowering the distances i.e e=mid-1;
            e=mid-1;
        }

    }

}

int main(){

    // vector<int> stalls = {10,1,2,7,5};
    vector<int> stalls = {1,2,4,8,9};
    int k=3;  // 3 cows

    int ans=-1;

    findMinDistance(stalls,k,ans);

    cout<<"The answer is "<<ans;
    
    return 0;
}