#include<iostream>
#include<unordered_map>
#include<vector>
#include<algorithm>
using namespace std;

bool solve(vector<int>&numsFrequency,vector<int>&customerDemand,int ithCustomer){

    if(ithCustomer>=customerDemand.size()) return true;

    for(int i=0;i<numsFrequency.size();i++){

        if(numsFrequency[i]>=customerDemand[ithCustomer]){

            numsFrequency[i]-=customerDemand[ithCustomer];
            if(solve(numsFrequency,customerDemand,ithCustomer+1)){
                return true;
            }
            // backtracking
            numsFrequency[i]+=customerDemand[ithCustomer];
        }

    }

    return false;

}

int main(){


    vector<int> nums = {1,2,3,4};
    vector<int> quantity = {2};

    unordered_map<int,int> numsFrequency;

    // traversing over nums and populating map with frequency of each num
    for(auto i:nums) numsFrequency[i]++;

    // this will store the frequency of each num
    vector<int> numsFrequencyArray;

    for(auto it:numsFrequency) numsFrequencyArray.push_back(it.second);

    sort(quantity.rbegin(),quantity.rend());
    cout<<solve(numsFrequencyArray,quantity,0);

    return 0;
}