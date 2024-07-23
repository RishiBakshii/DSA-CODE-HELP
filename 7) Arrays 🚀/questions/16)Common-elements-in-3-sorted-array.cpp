#include<iostream>
#include<set>
#include<vector>
using namespace std;

vector<int> findCommonElements(vector<int> arr1,vector<int> arr2,vector<int> arr3,int n1,int n2,int n3){

    int i,j,k=0;
    set<int> st;
    vector<int> ans;

    while(i<n1 && j<n2 && k<n3){

        if(arr1[i] == arr2[j] && arr2[j] == arr3[k]){
            i++;
            j++;
            k++;
            st.insert(arr1[i]);
        }
        else if(arr1[i]<arr2[j]){
            i++;
        }
        else if(arr2[j]<arr3[k]){
            j++;
        }
        else{
            k++;
        }

    }

    for(auto i : st){
        ans.push_back(i);
    }

    return ans;

}

int main(){

    vector<int> arr1 = {1,5,10,20,40,80};
    vector<int> arr2 = {6,7,20,80,100};
    vector<int> arr3 = {3,4,15,20,30,70,80,120};

    vector<int> ans =  findCommonElements(arr1,arr2,arr3,arr1.size(),arr2.size(),arr3.size());

    
    return 0;
}