#include<iostream>
using namespace std;

int main(){

    int n;
    cout<<"Enter the value of n :";
    cin>>n;

    for(int i=0;i<n;i++){
        
        // left stars
        for(int k=0;k<n-i;k++){
            cout<<"*";
        }

        // spaces
        for(int j=0;j<((2*i)+1);j++){
            cout<<" ";
        }

        // right stars
        for(int g=0;g<n-i;g++){
            cout<<"*";
        }

        cout<<endl;

    }
    for(int i=0;i<n;i++){
        
        // left stars
        for(int k =0;k<i+1;k++){
            cout<<"*";
        }

        // spaces
        for(int j=0;j<((2*(n-i))-1);j++){
            cout<<" ";
        }

        // right stars
        for(int g=0;g<i+1;g++){
            cout<<"*";
        }

        cout<<endl;

    }



    return 0;
}