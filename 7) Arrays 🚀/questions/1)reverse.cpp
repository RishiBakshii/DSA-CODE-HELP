#include<iostream>
using namespace std;

void printArray(int arr[],int n){
    
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }

}

void reverseArray(int arr[],int n){

    int s=0;
    int e=n-1;

    while(s<e) swap(arr[s++],arr[e--]);

}

int main(){
    
    int arr[5] = {10,20,30,40,50};
    reverseArray(arr,5);

    printArray(arr,5);


    return 0;
}