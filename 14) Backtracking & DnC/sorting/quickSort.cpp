#include<iostream>
#include<vector>
using namespace std;

void quickSort(vector<int>&arr,int start,int end){

    if(start>=end) return;

    int pivot = end;
    int i = start-1;
    int j = start;

    while(j<pivot){

        if(arr[j]<arr[pivot]){
            i++;
            swap(arr[i],arr[j]);
        }
        j++;

    }

    // i is the right position for the pivot element
    i++;
    swap(arr[i],arr[pivot]);
    quickSort(arr,start,i-1);
    quickSort(arr,i+1,end);

}

int main(){


    vector<int> arr = {10,30,20,60,50,40,80,100};
    quickSort(arr,0,arr.size()-1);
    for(auto i:arr) cout<<i<<" ";

    return 0;
}