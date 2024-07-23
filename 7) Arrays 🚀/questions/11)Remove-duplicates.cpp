#include<iostream>
#include<vector>
using namespace std;

int removeDuplicates(vector<int> &arr){

    int i=1,j=0;

    while(i<arr.size()){

        if(arr[i]==arr[j]){
            i++;
        }
        else{
            arr[++j]=arr[i++];
        }

    }

    return j+1;

}


int main(){



    
    return 0;
}