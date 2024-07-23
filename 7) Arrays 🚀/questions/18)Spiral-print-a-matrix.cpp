#include<iostream>
#include<vector>
using namespace std;


void spriralMatrix(vector<vector<int>> arr){


    int rows = arr.size();
    int columns = arr[0].size();

    int startingRow = 0;
    int endingCol = columns-1;
    int endingRow = rows-1;
    int startingColumn = 0;

    int totalElements = rows+1*columns+1;
    int count=0;

    while (count<totalElements){

        for(int i=startingColumn;i<=endingCol;i++){
            cout<<arr[startingRow][i];
            count++;
        }

        for(int i=startingRow+1;i<=endingRow;i++){
            cout<<arr[i][endingCol];
            count++;
        }

        for(int i=endingCol-1;i>=startingColumn;i--){
            cout<<arr[endingRow][i];
            count++;
        }
    }
    

}

int main(){
    
    vector<vector<int>> arr = {
        {1,2,3},
        {4,5,6},
        {7,8,9}
    };

    spriralMatrix(arr);


    return 0;
}