#include<iostream>
#include<math.h>
#include<limits.h>
using namespace std;

void solve(int n,int count,int&ans){
    
    // base cases
    if(n<0) return;
    if(n==0){
        ans = min(count,ans);
        return;
    }

    for(int i=1;i<=sqrt(n);i++){
        solve(n-(i*i),count+1,ans);
    }

}

int main(){

    int n = 12;
    int ans = INT_MAX;
    solve(n,0,ans);
    cout<<ans;

    return 0;
}