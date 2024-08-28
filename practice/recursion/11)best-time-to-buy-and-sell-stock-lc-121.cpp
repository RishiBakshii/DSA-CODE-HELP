#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;

void solve(vector<int>&prices,int&minPrice,int&maxProfit,int i){

    // BASE CASE
    if(i>=prices.size()) return;
    
    if(prices[i]<minPrice) minPrice=prices[i];
    
    int todaysProfit = prices[i]-minPrice;
    if(todaysProfit>maxProfit) maxProfit = todaysProfit;

    solve(prices,minPrice,maxProfit,i+1);

}

int main(){
    
    vector<int> prices = {7,1,5,3,6,4};
    int maxProfit = INT_MIN;
    int minPrice = INT_MAX;

    solve(prices,minPrice,maxProfit,0);

    cout<<"The maximum we can acheive is "<<maxProfit;

    return 0;
}