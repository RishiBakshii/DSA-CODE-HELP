#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>
using namespace std;


int garbageCollection(vector<string>& garbage, vector<int>& travel) {
    
    // In this question we have been a vector of garbage and travel
    // each garbage[i] represents how much garbage is in the ith house
    // each travel[i] represents the travel time between two houses

    // the garbage in each house i.e garbage[i] can be of 3 types
    // "M" => metal garbage
    // "G" => glass garbage
    // "P" => paper garbage

    // It takes 1 minute of time to pickup each garbage

    // so we have 3 garbage trucks in the city and each one is responsible for picking up 
    // a single type of garbage
    // so 1 truck might pickup M type of garbage
    // 2 truck might pickup G type of garbage
    // 3 truck might pickup P type of garbage

    // but here's a thing
    /*
    There are three garbage trucks in the city, each responsible for picking up one type of garbage. Each garbage truck starts at house 0 and must visit each house in order; however, they do not need to visit every house.

    Only one garbage truck may be used at any given moment. While one truck is driving or picking up garbage, the other two trucks cannot do anything.
    */

    // example 
    // garbage = ["G","P","GP","GG"], travel = [2,4,3]

    // approach
    // so first of all we need to figure out till what house a specific truck should go
    // as a truck that picks up only Paper garbage will go till only garbage[2]
    // as in garbage[3] there is no Paper garbage right??

    // once we get till each house index every truck has to go then we can easily calculate
    // the travel time

    // garbage[3] = ["GG"]
    // as we see that each house garbage is like a dustbin where there can be 
    // more than one type or number of garbages
    // so at each house we have to loop through the dustin

    // and then see that if
    // dustbin[i] == 'M'
    // dustbin[i] == 'G'
    // dustbin[i] == 'P'

    // In all three cases we need to increment the pickupTime for each type of truck 
    // and also have to update the lastHouseIndex of that truck
    // because if we are finding let'say G type of garbage in dustin of house[i]
    // then last house index for truck g should be i right??
    // because till here there is G type of garbage present that has to be picked up by truck that collects G garbage


    // METAL garbage picker truck
    int pickingTimeM=0;
    int travelTimeM=0;
    int lastHouseIndexM=0;

    // PAPER garbage picker truck
    int pickingTimeP=0;
    int travelTimeP=0;
    int lastHouseIndexP=0;

    // GLASS garbage picker truck
    int pickingTimeG=0;
    int travelTimeG=0;
    int lastHouseIndexG=0;

    // Looping through each house
    for(int i=0;i<garbage.size();i++){


        // dustbin of current house
        string currentHouseDustbin = garbage[i];

        // lopping through currentHouseDustbin
        // to see that which types of garbage does house[i] dustin contains
        for(int j=0;j<currentHouseDustbin.length();j++){

            // Now in the every house[i] dustbin
            // we can find three types of Garbages
            // "M" => metal garbage
            // "G" => glass garbage
            // "P" => paper garbage

            char garbageType = currentHouseDustbin[j];

            if(garbageType=='M'){
                // if the garbage type is of M
                
                // updating the lastHouseIndex for truck that picks up M type of garbage
                lastHouseIndexM=i;
                
                // updating the picking time
                // as picking up every garbage takes 1 minute of time
                // so it is getting incremented by 1
                pickingTimeM++;
            }
            if(garbageType=='P'){
                // if the garbage type is of P
                
                // updating the lastHouseIndex for truck that picks of P type of garbage
                lastHouseIndexP=i;

                // updating the picking time
                // as picking up every garbage takes 1 minute of time
                // so it is getting incremented by 1
                pickingTimeP++;
            }
            if(garbageType=='G'){
                // if the garbage type is of G
                
                // updating the lastHouseIndex for truck that picks of G type of garbage
                lastHouseIndexG=i;

                // updating the picking time
                // as picking up every garbage takes 1 minute of time
                // so it is getting incremented by 1
                pickingTimeG++;
            }

        }

    }

    // now we have the last house index for each truck
    // so basically now we know that till where each type of truck has to go

    // so now we will calculate the travel time 
    for(int i=0;i<lastHouseIndexM;i++){
        travelTimeM+=travel[i];
    }
    for(int i=0;i<lastHouseIndexG;i++){
        travelTimeG+=travel[i];
    }
    for(int i=0;i<lastHouseIndexP;i++){
        travelTimeP+=travel[i];
    }

    // final answer would be the sum of totalPickingTime + totalTravellingTime
    int totalPickingTime = pickingTimeG+pickingTimeM+pickingTimeP;
    int totalTravellingTime = travelTimeG+travelTimeM+travelTimeP;

    cout<<totalPickingTime+totalTravellingTime;;

}

int main(){

    vector<string> garbage = {"MMM","PGM","GP"};
    vector<int> travel = {3,10};

    garbageCollection(garbage,travel);

    return 0;
}