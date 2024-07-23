#include<iostream>
using namespace std;

int main(){

    int n;
    cout<<"Enter the value of n";
    cin>>n;

    for(int i =0;i<n;i++){

        // spaces
        for(int k=0;k<i;k++){
            cout<<" ";
        }

        // stars
        for(int j=0;j<n-i;j++){
            cout<<"* ";
        }

        cout<<endl;

    }

    return 0;
}