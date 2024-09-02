#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;

void solve(vector<int>&days,vector<int>&costs,int i,int dollarsSpent,int&ans){

    if(i>=days.size()) {
        ans = min(ans,dollarsSpent);
        return;
    }

    // 1 day pass
    solve(days,costs,i+1,dollarsSpent+costs[0],ans);

    // 7 day pass
    int passEndDate = days[i]+7-1;
    int k=i;
    while(k<days.size() && days[k]<=passEndDate) k++;
    solve(days,costs,k,dollarsSpent+costs[1],ans);

    // 30 day pass
    passEndDate = days[i]+30-1;
    k=i;
    while(k<days.size() && days[k]<=passEndDate) k++;
    solve(days,costs,k,dollarsSpent+costs[2],ans);

}

int main(){
    
    vector<int> days = {1,4,6,7,8,20};
    vector<int> costs = {2,7,15};

    int ans = INT_MAX;

    solve(days,costs,0,0,ans);

    cout<<ans;

    return 0;
}