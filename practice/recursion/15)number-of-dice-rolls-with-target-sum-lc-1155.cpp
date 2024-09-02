#include<iostream>

using namespace std;

void solve(int numberOfDices,int numberOfFaces,int target,int&ans){

    // base case

    if(numberOfDices<0) return;
    if(target<=0 && numberOfDices!=0) return;
    if(target==0 &&numberOfDices==0){
        ans = ans+1;
        return;
    }

    // for each dice we have k choices of numbers
    for(int i=1;i<=numberOfFaces;i++){
        solve(numberOfDices-1,numberOfFaces,target-i,ans);
    }

}

int main(){
    
    int n=2;
    int k=6;
    int target=7;

    int ans = 0;
    solve(n,k,target,ans);

    cout<<ans;

    return 0;
}