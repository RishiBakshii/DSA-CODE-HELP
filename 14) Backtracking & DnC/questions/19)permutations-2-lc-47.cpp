#include<iostream>
#include<vector>
#include<set>
#include<unordered_map>
using namespace std;

/*

one solution to remove duplicates is to use a set

*/

void printAnswer(vector<vector<int>>&ans){


    for(int i=0;i<ans.size();i++){
        for(int j=0;j<ans[i].size();j++){
            cout<<ans[i][j];
        }

        cout<<endl;
    }

}

void solve(vector<int>&nums,vector<vector<int>>&ans,int index){

    // base case
    if(index>=nums.size()-1) {
        ans.push_back(nums);
        return;
    }

    unordered_map<int,bool> visited;

    for(int j=index;j<nums.size();j++){


        // this condition will prevent from generating duplicate permutations
        if(visited.find(nums[j])!=visited.end()){
            continue;
        }

        visited[nums[j]] = true;

        swap(nums[index],nums[j]);
        solve(nums,ans,index+1);
        swap(nums[index],nums[j]);

    }


}

int main(){
    
    vector<int> nums = {1,2,1};
    vector<vector<int>> ans;

    solve(nums,ans,0);

    // but this will introduce extra time complexity
    /*

        // push ans in set
        set<vector<int>> st;

        for(auto e:ans) st.insert(e);
        ans.clear();
        for(auto e:st) ans.push_back(e);
    
    */

    printAnswer(ans);

    return 0;
}