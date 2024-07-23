#include<iostream>
#include<vector>
#include<math.h>
using namespace std;

void findSqrt(int x,double &ans){

    int s=0;
    int e=x;
    long long int mid=s+(e-s)/2;

    while(s<=e){

        long long int product = mid*mid;

        if(product==x){
            ans=mid;
            break;
        }
        if(product<x){
            ans=mid;
            s=mid+1;
        }
        else{
            e=mid-1;
        }


        mid=s+(e-s)/2;
    }


}

void calculatePrecision(double targetNumber,double &ans, int precisionCount){


    int s=0;
    int e=9;
    long long int mid = s+(e-s)/2;

    double precisionDivide =  pow(10.00,precisionCount);

    while(s<=e){

        double precisionVal = mid/precisionDivide;
        double num = ans + precisionVal;
        double product = num*num;

        if(product==targetNumber){
            ans=num;
            break;
        }
        if(product<targetNumber){
            ans=num;
            s=mid+1;
        }
        else{
            e=mid-1;
        }


        mid = s+(e-s)/2;
    }

}

int main(){
    
    int x=63;
    double ans = -1.0;
    findSqrt(x,ans);

    cout<<"Integer answer is "<<ans<<endl;

    int precisionCount = 3;

    for(int i=1;i<=precisionCount;i++){
        calculatePrecision(x,ans,i);
    }

    cout<<"Precision answer is "<<ans<<endl;

    /*
        cout be default print to only 5 precision

        if we want more precision printing then we can use
        printf("Precision sqrt : %.10f\n",ans);

        // here 10 represents the number of precision we want to print
        // f represents the "float";
    */
    
    return 0;
}