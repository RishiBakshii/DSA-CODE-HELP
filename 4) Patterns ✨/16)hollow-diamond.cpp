#include<iostream>
using namespace std;

int main(){
    
    int n;
    cout<<"Enter the value of n";
    cin>>n;

    for(int i=0;i<n;i++){

        // spaces
        for(int k=0;k<n-i-1;k++){
            cout<<" ";
        }

        // stars and spaces
        for(int j=0;j<i+1;j++){

            if(j==0 || j==i){
                cout<<"* ";
            }
            else{
                cout<<"  ";
            }
        }

        cout<<endl;

    }

    for(int i=0;i<n;i++){

        // spaces
        for(int k=0;k<i;k++){
            cout<<" ";
        }

        // stars and spaces
        for(int j=0;j<n-i;j++){

            if(j==0 || j==n-i-1){
                cout<<"* ";
            }
            else{
                cout<<"  ";
            }
        }

        cout<<endl;

    }

    return 0;
}