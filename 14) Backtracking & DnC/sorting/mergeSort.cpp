#include<iostream>
#include<vector>
using namespace std;

// TC => O(nlogn)
void printArray(vector<int>&arr){

    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

// it is just a function for understanding
// but it is not being used in mergeSort algo logic
void mergeSortedArray(vector<int>&arr,vector<int>&arr2,vector<int>&ans){

    int i=0;
    int j=0;

    while(i<arr.size() && j<arr.size()){

        if(arr[i]<arr2[j]){
            ans.push_back(arr[i]);
            i++;
        }
        else{
            ans.push_back(arr2[j]);
            j++;
        }

    }

    while(i<arr.size()){
        ans.push_back(arr[i]);
        i++;
    }

    while(j<arr2.size()){
        ans.push_back(arr2[j]);
        j++;
    }

}


void merge(vector<int>&arr,int s,int e,int mid){


    // create left and right arrays
    int leftLength = mid-s+1;
    int rightLength = e-mid;

    int *leftArray = new int[leftLength];
    int *rightArray = new int[rightLength];

    // fill or copy the left and right arrays
    int index = s;

    // copying into left array
    for(int i=0;i<leftLength;i++){
        leftArray[i] = arr[index];
        index++;
    }

    // copying into right array
    index = mid+1;
    for(int i=0;i<rightLength;i++){
        rightArray[i] = arr[index];
        index++;
    }

    // merge logic
    int leftIndex = 0;
    int rightIndex = 0;
    int mainArrayIndex = s;

    while(leftIndex<leftLength && rightIndex < rightLength){

        if(leftArray[leftIndex] < rightArray[rightIndex]){
            arr[mainArrayIndex] = leftArray[leftIndex];
            leftIndex++;
            mainArrayIndex++;
        }
        else{
            arr[mainArrayIndex] = rightArray[rightIndex];
            rightIndex++;
            mainArrayIndex++;
        }

    }

    while(leftIndex < leftLength){
        arr[mainArrayIndex] = leftArray[leftIndex];
        leftIndex++;
        mainArrayIndex++;
    }
    while(rightIndex < rightLength){
        arr[mainArrayIndex] = rightArray[rightIndex];
        rightIndex++;
        mainArrayIndex++;
    }

    // delete heap memory
    delete[] leftArray;
    delete[] rightArray;

}

void mergeSort(vector<int>&arr,int s,int e){

    // base case
    if(s>=e) return;

    int mid = s+(e-s)/2;

    // left part recursion se solve karwao
    mergeSort(arr,s,mid);
    // right part recursion se solve karwao
    mergeSort(arr,mid+1,e);
    // dono parts ko merge kardo
    merge(arr,s,e,mid);

}


int main(){

    vector<int> arr = {10,80,110,90,50,30,40,20};
    int s = 0;
    int e = arr.size()-1;

    // before
    printArray(arr);
    cout<<endl;

    // merge sort getting applied
    mergeSort(arr,s,e);

    // after
    printArray(arr);

    return 0;
}