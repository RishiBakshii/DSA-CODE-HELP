#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
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

        // first condition checks for the negative value of the target and prevents a call
        // second condition ensures that we do not pick up same element twice
        // i>index means that in a new recursive call for example index=1 and i=1
        // so when i>index i.e not in the first iteration then check that 
        // if the current candidate is eqaul to previous or not
        // so that's how our conditions are working
        if(target-candidates[i]>=0 && !(i>index && candidates[i]==candidates[i-1])){
            current.push_back(candidates[i]);
            solve(candidates,target-candidates[i],ans,current,i+1);
            current.pop_back();
        }
    }

}

int main(){

    vector<int> candidates = {2,5,2,1,2};
    int target = 5;

    // sorting the candidates for sorted picking
    // so that in the set duplicates can be easily identified and removed 
    sort(candidates.begin(),candidates.end());

    vector<vector<int>> ans;
    vector<int> current;
    
    solve(candidates,target,ans,current,0);


    // this code below is increasing the time complexity
    // set<vector<int>> st;
    // we need to find another solution
    // for(auto e:ans){
    //     // this is taking O(nlogn) time
    //     st.insert(e);
    // }
    // ans.clear();

    // for(auto e:st){
    //     ans.push_back(e);  // only unique vectors
    // }


    printAnswer(ans);

    return 0;
} 