#include<iostream>
#include<vector>
using namespace std;

int main(){

    vector<vector<int>> arr={
                            {1,2,3,4},
                            {5,6,7,8},
                            {9,10,11,12}
                        };
    int row=3;
    int cols=4;
    int currentRow = 0;

    for(int i=0;i<cols;i++){


        if(currentRow%2!=0){
            for(int j=row-1;j>=0;j--){
                cout<<arr[j][i]<<" ";
            }
        }
        else{
            for(int j=0;j<row;j++){
                cout<<arr[j][i]<<" ";
            }
        }

        currentRow++;

    }

    return 0;
}