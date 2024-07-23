#include<iostream>
#include<vector>
using namespace std;


void printArray(vector<int> arr){
    for(int i:arr){
        cout<<i<<" ";
    }
}


void insertionSort(vector<int> &arr){

    int n=arr.size();

    for(int i=1;i<n;i++){

        int key = arr[i];
        int j=i-1;

        // while j<=0 and till our i i.e key is smaller than its previous elements
        // in every iteration moving the previous element in place of i
        // basically moving a previous element in forward place
        // by doing arr[j+1] = arr[j]
        // then doing j-- , so that now it checks for further previous element 
        while(j>=0 && key<arr[j]){
            arr[j+1] = arr[j];
            j--;
        }

        // now here j is out of bound i.e -1;
        // so what we will do is j+1 i.e 0
        // we will put there the key
        arr[j+1] = key; // insertion

    }

}

int main(){

    vector<int> arr = {5,4,3,2,1};
    insertionSort(arr);
    printArray(arr);
    
    return 0;
}