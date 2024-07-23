#include<iostream>
#include<vector>
using namespace std;

void printArray(vector<vector<int>> arr){

    
    int rows = arr.size();
    int columns = arr[0].size();

    for(int i=0;i<rows;i++){

        for(int j=0;j<columns;j++){
            cout<<arr[i][j]<<" ";
        }

        cout<<endl;

    }
}

void reverse(vector<int> &arr){

    int s=0;
    int e = arr.size()-1;

    while(s<e){
        swap(arr[s++],arr[e--]);
    }

}

void transpose(vector<vector<int>> &arr){

    int rows = arr.size();
    int columns = arr[0].size();

    for(int i=0;i<rows;i++){

        for(int j=i;j<columns;j++){
            swap(arr[i][j],arr[j][i]);
        }

    }

}

void reverseEachRowsColumns(vector<vector<int>> &arr){

    for(int i=0;i<arr.size();i++){
        reverse(arr[i]);
    }

}

int main(){
    
    vector<vector<int>> arr = {
        {1,2,3},
        {4,5,6},
        {7,8,9},
    };

    transpose(arr);
    reverseEachRowsColumns(arr);
    printArray(arr);

    return 0;
}