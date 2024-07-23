#include<iostream>
using namespace std;

void printArray(int arr[],int n ){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}

void shiftArrayByN(int arr[],int n){

    

}

int main(){

    int arr[6]={10,20,30,40,50,60};
    shiftArrayByN(arr,6);
    printArray(arr,6);

    return 0;
}
 