// this problem is also called dutch-nation-problem

#include<iostream>
#include<vector>
using namespace std;

void sort012(vector<int>& nums) {

    int l=0;
    int m=l;
    int h=nums.size()-1;

    while(m<=h){

        if(nums[m]==0){
            swap(nums[l++],nums[m++]);
        }
        else if(nums[m]==2){
            swap(nums[h--],nums[m]);
        }
        else{
            m++;
        }
    }

}

int main(){
    
    return 0;
}

