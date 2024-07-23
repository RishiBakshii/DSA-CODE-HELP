#include<iostream>
#include<vector>
using namespace std;

int findOddOccuringElement(vector<int>& nums) {

        int n = nums.size();
        int s = 0;
        int e = n-1;
        int mid = s+(e-s)/2;

        int currentVal = nums[mid];
        int leftVal = -1;
        int rightVal = -1;

        while(s<=e){

            currentVal = nums[mid];

            if(mid+1<n) {
                rightVal = nums[mid+1];
            } 
            if(mid-1>=0){
                leftVal = nums[mid-1];
            } 

            // when there is only single element
            if(s==e){
                return nums[s];
            }

            // when the mid is unique from adjacent elements
            if(currentVal!=leftVal && currentVal!=rightVal){
                return currentVal;
            }

            // left duplicate
            if(currentVal!=rightVal && currentVal==leftVal){
                int pairFirstElementIndex = mid-1;

                if(pairFirstElementIndex&1){
                    // we are right side
                    // move to left
                    e=mid-1;
                }
                else{
                    // we are on left side
                    // move to right
                    s=mid+1;
                }
            }

            // right duplicate
            if(currentVal!=leftVal && currentVal==rightVal){
                int pairFirstElementIndex = mid;

                if(pairFirstElementIndex&1){
                    // we are right side
                    // move to left
                    e=mid-1;
                }
                else{
                    // we are on left side
                    // move to right
                    s=mid+1;
                }
            }

            mid=s+(e-s)/2;
            leftVal = -1;
            rightVal = -1;
        }

        return -1;
    }


int main(){
    
    vector<int> arr = {1,2,2,3,3};
    int ans = findOddOccuringElement(arr);

    cout<<endl;
    cout<<"Answer : "<<ans<<endl;

    return 0;
}