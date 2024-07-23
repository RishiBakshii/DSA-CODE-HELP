/*

Approaches to solve this
1) sorting
2) counting
3) 2-pointer

*/

#include<iostream>
#include<vector>
using namespace std;

void sort0and1(vector<int> &arr){

    int s = 0;
    int e = arr.size()-1;

    if(arr[s]==0){
        s++;
    }
    if(arr[e]==1){
        e--;
    }

    while(s<e){

        if(arr[e]==0 && arr[s]==1){
            swap(arr[e],arr[s]);
            s++;
            e--;
        }
        else{
            if(arr[e]==1){
                e--;
            };
            if(arr[s]==0){
                s++;
            };
        }

    }

}

int main(){
    
    vector<int> arr={0,1,1,1,1,1,0,0,1,1,1,0,0,0,0,1,0,0,1,0,1,0,1,0,1,0,1,0,1,0,0,0,0,1,1,1};
    sort0and1(arr);
    for(auto i:arr){
        cout<<i<<" ";
    }

    return 0;
}