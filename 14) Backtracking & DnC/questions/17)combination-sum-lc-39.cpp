#include<iostream>
#include<vector>
using namespace std;

void printAnswer(vector<vector<int>>&ans){


    for(int i=0;i<ans.size();i++){
        for(int j=0;j<ans[i].size();j++){
            cout<<ans[i][j];
        }

        cout<<endl;
    }

}

void solve(vector<int>&candidates,int target,vector<vector<int>>&ans,vector<int>&current,int index){

    // base case
    if(target==0){
        ans.push_back(current);
        return;
    }

    for(int i=index;i<candidates.size();i++){

        if(target-candidates[i]>=0){
            current.push_back(candidates[i]);
            solve(candidates,target-candidates[i],ans,current,i);
            current.pop_back();
        }
    }

}

int main(){

    vector<int> candidates = {2,3,6,7};
    int target = 7;
    vector<vector<int>> ans;
    vector<int> current;
    
    solve(candidates,target,ans,current,0);
    printAnswer(ans);

    return 0;
} 