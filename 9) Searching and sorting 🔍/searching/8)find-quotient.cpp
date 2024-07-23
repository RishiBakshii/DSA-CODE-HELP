#include<iostream>
#include<vector>
using namespace std;

void findQuotient(int divisor,int dividend,int &ans){


    int s=0;
    int e=dividend;
    int mid = s+((e-s)>>1);

    while(s<=e){

        int product = divisor*mid;

        if(product==dividend){

            ans=mid;
            break;

        }
        else if(product<dividend){
            ans=mid;
            s=mid+1;
        }
        else{
            e=mid-1;
        }

        mid = s+((e-s)>>1);

    }


}

int main(){

    int ans=-1;
    int dividend = 10;
    int divisor = -2;

    findQuotient(abs(divisor),abs(dividend),ans);

    if(dividend < 0 && divisor > 0 || divisor < 0 && dividend > 0){
        ans = 0-ans;
    }

    cout<<ans;

    return 0;
}