#include<iostream>
#include<vector>
using namespace std;

void printArray(vector<int> arr){
    
    cout<<endl;
    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

vector<int> findComplement(vector<int> arr){

    int n = arr.size();
    vector<int> twoComp(n+1,0);

    // 1) flip the bits
    for(int i=n-1;i>=0;i--){
        cout<<i<<" ";
        twoComp[i+1] = arr[i]==0?1:0;
    }

    // 2) add one from the right side 
    int carry = 1;
    for(int i=twoComp.size()-1;i>0;i--){

        int sum = twoComp[i]+carry;
        int lastDigit = sum%2;
        twoComp[i]=lastDigit;
        carry = sum/2;

        if(carry=0) break;

    }

    if(carry){
        twoComp[0]=carry;
    }

    return twoComp;

}

int main(){

    vector<int> arr = {0,0,0,1,1,0,1,0};
    vector<int> ans =  findComplement(arr);
    printArray(ans);

    
    return 0;
}