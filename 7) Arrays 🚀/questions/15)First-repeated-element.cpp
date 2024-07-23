#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

void print(vector<int> arr){
    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }
}

// method 1
int firstRepeated(vector<int> &nums){

    int i=0;
    int j=1;

    while(i<nums.size()-1){

        if(nums[i]==nums[j]){
            return i+1;
        }
        else if(j==nums.size()-1){
            i++;
            j=i+1;
        }
        else{
            j++;
        }
    }

    return -1;

}


int firstRepeatedUsingHashCount(vector<int> &nums){


    unordered_map<int,int> hash;

    // storing the counts
    for(int i=0;i<nums.size();i++){
        hash[nums[i]]++;
    }

    // iterating over hash 
    for(int i=0;i<nums.size();i++){
        if(hash[nums[i]]>1){
            return i+1;
        }
    }

    return -1;

}

int main(){
    
    vector<int> nums = {1,5,3,4,3,5,6};
    // cout<<firstRepeated(nums);

    cout<<firstRepeatedUsingHashCount(nums);


    return 0;
}