#include<iostream>
using namespace std;

int main(){

    int n;
    cout<<"Enter the value of n: ";
    cin>>n;

    for(int i=0;i<n;i++){

        for(int j=0;j<i+1;j++){

            if(i<2 || i==n-1){
                cout<<" * ";
            }
            else{
                if(j==0 || j==i){
                    cout<<" * ";
                }
                else{
                    cout<<" - ";
                }
            }


        }
        cout<<endl;

    }

    return 0;
}