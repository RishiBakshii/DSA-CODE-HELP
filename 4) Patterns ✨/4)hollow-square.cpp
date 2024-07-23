#include<iostream>
using namespace std;

int main(){

    int squareDimension;

    cout<<"Enter the sqaure dimension : ";
    cin>>squareDimension;

    for(int i=0;i<squareDimension;i++){

        for(int j=0;j<squareDimension;j++){

            if(i == 0 || i == squareDimension -1){
                cout<<" * ";
            }
            else{
                if(j==0 || j== squareDimension -1){
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