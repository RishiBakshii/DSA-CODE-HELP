// TC = SC => O(n)

#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;

void solve(vector<int>&prices,int i,int&maxProfit, int&minPrice){

    // base case
    if(i==prices.size()) return;

    if(prices[i]<minPrice) minPrice = prices[i];
    int todaysProfit = prices[i] - minPrice;
    if(todaysProfit>maxProfit) maxProfit = todaysProfit;

    solve(prices,i+1,maxProfit,minPrice);

}

int main(){
    
    vector<int> prices = {7,1,5,3,6,4};
    int maxProfit = INT_MIN;
    int minPrice = INT_MAX;

    solve(prices,0,maxProfit,minPrice);

    cout<<maxProfit;

    return 0;
}