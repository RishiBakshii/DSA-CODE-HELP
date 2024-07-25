#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool isPossibleSolution(vector<int>&cooks, int p, int mid){

    // as because first parantha will be getting made
    int paranthaCount=1;

    // how much time can be given to each cook for making paranthas
    int perCookTimeLimit = mid;

    // for tracking the time limit for each cook
    int timePassed = 0;

    // starting from first cook i.e i=0
    int i=0;

    // for getting total cooks
    int n=cooks.size();

    // loop will terminate on two conditions
        // 1) if it reaches the end (i.e from 1 cook to last cook)
        // 2) if all the pranthas are made i.e p==0
    while(i<n && p){

        int rank = cooks[i]; // rank of current cook

        // (rank*paranthaCount) will give us the time 
        // that this particular cook will take for making this current parantha
        int timeForMakingCurrentParantha = rank*paranthaCount;

        // cheking if this cook can make this parantha
        // without breaching his overall time limit
        if(timeForMakingCurrentParantha+timePassed>perCookTimeLimit){

            // if the time is over for this cook
            // we are moving to next cook i.e i++
            i++;

            // resetting the parantha count to 1 for next cook
            paranthaCount=1;

            // resetting the time limit for next cook
            timePassed=0;

        }
        else{
            // if the current cook is working under his time limit
            // then he will keep on making paranthas i.e p--;
            p--;

            // increasing the parantha count for current cook 
            paranthaCount++;

            // and on every parantha he makes his clock will be ticking
            timePassed+=timeForMakingCurrentParantha;
        }

    }

    return p<=0;

}

void findMinimumTime(vector<int>&arr, int p, int l, int &ans){

    // lower bound
    int s=0;

    // we can calulate the upper bound for time by this
    // let say these were the cooks ranks => {1,2,3,4};

    // imagine if we give the task of making all the paranthas to the cook with the highest rank (i.e the most inefficient cook)
    // in this case it is rank 4 
    // so the time taken by that cook will be the highest right?
    // totalTime => rank*paranthaNumber => (4*1) + (4*2) + (4*3) + (4*4) + (4*5) + (4*6) + (4*7) + (4*8) + (4*9) + (4*10)

    // applying some basic math formula
    // take 4 common 
    // 4 * [1+2+3+4+5+6+7+8+9+10]
    // now for calulating the sum [1+2+3+4+5+6+7+8+9+10] there is a formula in maths 
    // i.e (n*(n+1))/2  # here n will be the number of paranthas i.e p;
    // so the whole formula would be 
    // 4*(n*(n+1))/2 # replace 4 with max_element

    int e=*max_element(arr.begin(),arr.end())*((p*(p+1))/2); // applying derived formula for calculating end i.e upper bound of time

    while (s<=e){

        int mid = s+(e-s)/2;

        if(isPossibleSolution(arr,p,mid)){
            ans=mid;
            e=mid-1;
        }
        else{
            s=mid+1;
        }

    }
    
}


int main(){
    
    int numberOfTestCases;
    cin>>numberOfTestCases;

    while(numberOfTestCases--){

        int ans=-1;
        int paranthas,numberOfCooks;
        cin>>paranthas>>numberOfCooks;

        vector<int> cooksRanks;

        while(numberOfCooks--){
            int cookRank;
            cin>>cookRank;
            cooksRanks.push_back(cookRank);
        }

        findMinimumTime(cooksRanks,paranthas,cooksRanks.size(),ans);

        cout<<ans;

    }


    return 0;
}