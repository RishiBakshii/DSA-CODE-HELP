#include<iostream>
#include<vector>
#include<numeric>
#include<algorithm>
using namespace std;

void solve(vector<int>&sqaureSides,vector<int>&matchsticks,int i,bool&ans){


    // if all matchsticks are consumed and all swaure sides are 0
    if(i>=matchsticks.size() && sqaureSides[0]==0 && sqaureSides[1]==0 && sqaureSides[2]==0 && sqaureSides[3]==0){
        ans=true;
        return;
    }

    // we will be putting ith matchstick on every 4 side of the sqaure
    for(int j=0;j<sqaureSides.size();j++){

        if(sqaureSides[j]-matchsticks[i]>=0){
            sqaureSides[j]-=matchsticks[i];
            solve(sqaureSides,matchsticks,i+1,ans);
            sqaureSides[j]+=matchsticks[i];  // backtracking
        }
    }

}

int main(){

    vector<int> matchsticks = {1,2,1,2,3,1,1,1,1,1,1,1,4};

    int sum = accumulate(matchsticks.begin(),matchsticks.end(),0);

    bool ans = false;

    // if sum of the matchsticks
    // can be divided into 4 equal sides
    // i.e sum%4 leaves no remainder
    // then only we will go for the solution

    // also checking if matchsticks are not less than 10
    if(sum%4==0 && matchsticks.size()>=4){
        int eachSquareSide = sum/4;
        vector<int> squareSides(4,sum/4);

        // sorting the matchsticks in desending order so that we place 
        // the bigger matchsticks first and can get to the conslusion faster
        // thus minimimzing recursive calls
        sort(matchsticks.rbegin(),matchsticks.rend());
        solve(squareSides,matchsticks,0,ans);
    }


    cout<<ans;

    return 0;
}