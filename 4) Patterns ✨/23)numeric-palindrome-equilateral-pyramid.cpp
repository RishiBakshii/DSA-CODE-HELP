#include<iostream>
using namespace std;

int main(){
    
    int n;
    cout<<"Enter the value of n";
    cin>>n;

    for(int i=0;i<n;i++){

        // spaces
        for(int k=0;k<n-i-1;k++){
            cout<<"   ";
        }

        // middle
        for(int g=0;g<i+1;g++){
            cout<<" "<<g+1<<" ";
        }

        if(i>0){

            for(int j=i;j>=1;j--){
                cout<<" "<<j<<" ";
            }
        }


        cout<<endl;


    }

    return 0;
}