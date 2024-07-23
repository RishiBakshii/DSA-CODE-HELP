#include<iostream>
#include<limits.h>
using namespace std;

void print(int arr[],int size){
    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }
}


void print(int arr[], int size) {
    for(int index=0; index<size; index++) {
        cout << arr[index] <<  " ";
    }
}

void solve1(int arr[], int n) {
    for(int i=0; i<n; i++) {
        arr[i] = arr[i] * 10;
    }
}

bool findTarget(int arr[], int size, int target) {

    for(int i=size-1; i>=0; i--) {
        if(arr[i] == target) {
            return true;
        }
    }
    return false;




    //traverse the entire array
    // for(int i=0; i<size; i++) {

    //     if( arr[i] == target) {
    //         //found
    //         return true;
    //     }
    // }
    // ///agar aap yaha tk pohoch gye toh
    // //iska mtlb poora loop chal chuka hai
    // //iska matlab poore loop me kahin bhi target nahi mila 
    // //iska mtlb element not found
    // //iskat matlab return false;
    // return false;
}

int findMax(int arr[], int size) {
    int maxAns = INT_MIN;
    for(int i=0; i<size; i++) {
        maxAns = max(maxAns, arr[i]);
    }
    return maxAns;
}

void printZeroesAndOnes(int arr[], int n) {
    int zeroCount = 0;
    int oneCount = 0;

    //traverse Array
    for(int i=0; i<n; i++) {
        int currElement = arr[i];
        
        if(currElement == 0) {
            zeroCount++;
        }
        if(currElement == 1) {
            oneCount++;
        }
    }
    cout << "Total Zeroes: " << zeroCount << endl;
    cout << "Total Ones: " << oneCount << endl;
}

void extremePrint(int arr[], int n) {
    int i = 0;
    int j = n-1;

    while(i <= j) {
        if(i == j) {
            cout << arr[i] << " ";
            break;
        }
        else {
            cout << arr[i] << " ";
            i++;
            cout << arr[j] << " ";
            j--;
        }

    }
}


int main(){
    
    // creation
    // int arr[5] = {1,2,3,4,5};

    int arr[100];
    int size;

    cout<<"Enter the array size : "<<endl;
    cin>>size;

    for(int i=0;i<size;i++){
        cin>>arr[i];
    }

    print(arr,size);



    return 0; 
}