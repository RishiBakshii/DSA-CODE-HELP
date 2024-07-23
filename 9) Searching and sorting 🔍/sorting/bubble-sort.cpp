#include<iostream>
#include<vector>
using namespace std;

void printArray(vector<int> arr){
    for(int i:arr){
        cout<<i<<" ";
    }
}

void bubbleSort(vector<int> &arr){

    int n=arr.size();

    for(int i=0;i<n-1;i++){

        // for every ith iteration j is going to n-i-1
        // as the last ith elements are getting sorted
        for(int j=0;j<n-1-i;j++){
            if(arr[j]>arr[j+1]) swap(arr[j],arr[j+1]);
        }

    }

}


int main(){
    
    vector<int> arr = {5,4,3,2,1};
    bubbleSort(arr);
    printArray(arr);


    return 0;
}