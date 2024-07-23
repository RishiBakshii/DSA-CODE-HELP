// TC: O(log(max(piles))) * O(n) -> O(n*log(max(piles)))

#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
using namespace std;

bool canKokoFinishBananasWithKSpeed(vector<int> &piles, int h, int k){

    int totalHoursToFinishBananasWithKSpeed = 0;

    for(int i:piles){
        totalHoursToFinishBananasWithKSpeed+=ceil(i/double(k));
    }

    return totalHoursToFinishBananasWithKSpeed<=h;

}

void minEatingSpeed(vector<int> &piles, int h, int &ans){

    int s=0;
    int e = *(max_element(piles.begin(),piles.end()));
    int mid=s+(e-s)/2;

    while(s<=e){

        int k=mid;

        if(canKokoFinishBananasWithKSpeed(piles,h,k)){
            ans=k;
            e=mid-1;
        }
        else{
            s=mid+1;
        }

        mid=s+(e-s)/2;

    }

}

int main(){

    vector<int> arr = {3,6,7,11};
    int ans=-1;
    minEatingSpeed(arr,8,ans);

    cout<<ans;
    
    return 0;
}