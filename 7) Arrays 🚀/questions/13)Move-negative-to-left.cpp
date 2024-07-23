#include<iostream>
#include<vector>
using namespace std;

void moveNegativeNumbersToLeft(vector<int> &arr){

    int l=0;
    int h=arr.size()-1;

    while(l<h){

        if(arr[l]<0){
            l++;
        }
        else if(arr[h]>0){
            h--;
        }
        else{
            swap(arr[l++],arr[h--]);
        }
        
    }

}

void print(vector<int> arr){
    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }
}

int main(){
    
    vector<int>arr = {-5,1,2,-3,4,-5,6,-20,-89,-45};
    moveNegativeNumbersToLeft(arr);
    print(arr);


    return 0;
}