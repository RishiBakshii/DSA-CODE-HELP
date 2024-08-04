#include<iostream>
#include<vector>
#include<algorithm>
#include<limits.h>
using namespace std;

int convertToMin(string s){
    int hr = stoi(s.substr(0,2));
    int min = stoi(s.substr(3,2));
    return 60*hr + min;
}

int main(){
    
    vector<string> timePoints = {"23:59","00:00"};

    vector<int> minutes;

    for(auto time:timePoints){
        minutes.push_back(convertToMin(time));
    }

    sort(minutes.begin(),minutes.end());

    int ans = INT_MAX; // MIN DIFFERENCE

    for(int i=0;i<minutes.size()-1;i++){
        ans = min(ans,minutes[i+1]-minutes[i]);
    }

    int antiClockWiseDifferenceBetweenLastAndFirstMin = (1440 + minutes[0]) - minutes[minutes.size()-1];
    ans = min(ans,antiClockWiseDifferenceBetweenLastAndFirstMin);

    // after calculating all the differences in minutes and storing the most minimum in ans
    // we also need to calculate the difference of last one in anti-clockwise-direction
    // so let's say they are hours like this
    // 1:00, 2:00, 5:00 , 10:00
    // each hours has 60 minutes
    // so 2 hours will be having 2*60 minutes i.e hour * 60
    // converting the hours into minutes
    // 60,120,300,600
    // so we have calculated absolute differences like
    // [60 - 120] , [120 - 300] , [300 - 600]
    // so it results in
    // 60 , 180 , 300 
    // so the minimum minutes difference here is 60 so this will be our answer

    // **but we have forgot a very essestial thing here and this is 
    // we have not considerred the anti-clockwise difference
    // between the first min and the last min
    // so right now we considered differences in clockwise direction which is fine
    // but we also have to consider the time difference in anti clockwise for the first min and last min
    // so in 24 hours time format 
    // the top center of the clock would be 00:00 i.e 12:00 or we can say 24:00 
    // so the minutes there would be hours * 24 = 24*60 == 1440;
    // so in order to calculate the difference between the first min and last min it would be
    // first min = 1440 + mins[0];  # as min[0] i.e 60 is probably after the 24:00 or 12:00 or 00:00 that is why we are adding
                                    // 1440 in min[0] as it is the right thing to do
    // lastMin  = mins[mins.size()-1];
    // anticlockwiseTimeDiff =  firstMin -  lastMin
    // so this is how we can calulcate that
    // firstMin = 1440 + 60 => 1500
    // lastMin = 300
    // diff = 1500-300 => 1200;
    // and now 1200 will also be compared with ans
    // because if this is the smallest then this will be taken
    // ans = min(ans,antiClockWiseDifferenceBetweenLastAndFirstMin);


    return 0;
}