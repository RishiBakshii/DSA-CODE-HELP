#include<iostream>
#include<vector>
using namespace std;

void print(vector<int> arr){
    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }
}

// method 1
void findMissingElementFromDuplicates(vector<int> &arr){

    int size=arr.size();

    for(int i=0;i<size;i++){

        int index = abs(arr[i]);

        if(arr[index-1]>0){
            arr[index-1] *= -1;
        }

    }

    // all positive indexes are missing
    for(int i=0;i<size;i++){
        if(arr[i]>0){
            cout<<i+1<<" ";
        }
    }

}

// method 2
void sortingAndSwapping(vector<int> &arr){

    int i=0;
    int n = arr.size();

    while(i<n){

        int index = arr[i]-1;

        if(arr[i]!=arr[index]){
            swap(arr[i],arr[index]);
        }
        else{
            i++;
        }

    }

    for(int i=0;i<n;i++){

        if(arr[i]!=i+1){
            cout<<i+1;
        }

    }

}


int main(){
    
    vector<int> arr = {1,2,3,3,5};

    findMissingElementFromDuplicates(arr);
    // sortingAndSwapping(arr);

    return 0;
}