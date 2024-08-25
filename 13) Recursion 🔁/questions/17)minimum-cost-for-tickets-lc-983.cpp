#include<iostream>
#include<vector>
using namespace std;

// TC=> O(3^n) // as we have 3 choices in every step
// SC => O(n+1) => O(n)

int minCostTickets_helper(vector<int>&days,vector<int>&costs,int i){


    // base
    if(i>=days.size()) return 0;

    // sol for 1 case

    // 1 day pass taken
    int cost1 = costs[0] + minCostTickets_helper(days,costs,i+1);


    // 7 day pass taken
    int j = i;
    int endDayOfPass = days[i] + 7 - 1;
    while(j<days.size() && days[j]<=endDayOfPass) j++;
    int cost2 = costs[1] + minCostTickets_helper(days,costs,j);

    // 30 day pass taken
    j = i;
    endDayOfPass = days[i] + 30 - 1;
    while(j<days.size() && days[j]<=endDayOfPass) j++;
    int cost3 = costs[2] + minCostTickets_helper(days,costs,j);

    return min(cost1,min(cost2,cost3));

}


int main(){

    vector<int> days = {1,4,6,7,8,20};
    vector<int> costs = {2,7,15};

    cout<<minCostTickets_helper(days,costs,0);
    
    return 0;
}