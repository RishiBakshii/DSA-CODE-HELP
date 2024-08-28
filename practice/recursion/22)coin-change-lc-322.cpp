#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;


void solve(vector<int>&coins,int coinCount,int amount,int&ans){

    // base cases
    if(amount<0) return;

    if(amount==0){
        ans = min(ans,coinCount);
        return;
    }

    for(auto coin:coins) {
        solve(coins,coinCount+1,amount-coin,ans);
    }

}

int main(){

    vector<int> coins = {1};
    int amount = 0;


    int ans = INT_MAX;
    solve(coins,0,amount,ans);

    if(ans==INT_MAX) ans = -1;

    cout<<ans;
    
    return 0;
}