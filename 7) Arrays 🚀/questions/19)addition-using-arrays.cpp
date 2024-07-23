#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


void addTwoNumbersUsingArrays(vector<int> arr1,vector<int> arr2){

    int i = arr1.size()-1;
    int j = arr2.size()-1;
    int carry = 0;

    vector<int> ans;

    while(i>=0 || j>=0){


        int secondNumber = arr2[j];

        if(j<0){
            secondNumber = 0;
        }

        int sum = arr1[i] + secondNumber + carry;
        carry=0;

        if(sum>9){
            int lastDigit = sum%10;
            ans.push_back(lastDigit);
            carry = sum/10;
        }
        else{
            ans.push_back(sum);
        }

        i--;
        j--;


    }

    reverse(ans.begin(),ans.end());

    for(auto i : ans){
        cout<<i;
    }

}

int main(){
    
    vector<int> arr1={7,2,4,6,9};
    vector<int> arr2={3,10,2,5};

    addTwoNumbersUsingArrays(arr1,arr2);

    return 0;
}