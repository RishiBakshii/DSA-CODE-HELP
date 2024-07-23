#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;


void printArray(vector<int> arr){
    for(int i:arr){
        cout<<i<<" ";
    }
}

void selectionSort(vector<int> &arr){

    int minElementIndex = 0;
    int n=arr.size();

    for(int i=0;i<n-1;i++){

        minElementIndex = i; 

        for(int j=i+1;j<n;j++){
            if(arr[j]<arr[minElementIndex]){
                minElementIndex = j;
            }
        };
        
        // swapping of minimum element at ith index
        swap(arr[i],arr[minElementIndex]);

    }


}

int main(){
    
    vector<int> arr = {5,4,3,2,1};
    selectionSort(arr);
    printArray(arr);

    return 0;
}