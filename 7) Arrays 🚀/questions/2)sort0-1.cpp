#include<iostream>
#include<algorithm>
using namespace std;

void printArray(int arr[],int n){

    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }

}

void sort0and1(int arr[],int n){

    bool isSwapped=true;

    for(int i=0;i<n;i++){

        cout<<"***********************************"<<endl;
        cout<<"outer iteration "<<i<<" "<<endl;
        printArray(arr,6);
        cout<<endl;
        cout<<"***********************************"<<endl<<endl<<endl;


        for(int j=0;j<n-1;j++){ 
            
            isSwapped=false;
 
            if(arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);
                isSwapped=true; 
            }
        }

    } 

}


int main(){

    int arr[6]={0,0,1,1,0,1};

    sort0and1(arr,6);
    printArray(arr,6);

    return 0;
}