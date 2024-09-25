#include<iostream>
#include<vector>
using namespace std;

void solve(int&n,int&ans, int currNum,vector<int>&output){

    // base case
    if(currNum>n) {
        ans++;
        return;
    }

    for(int i=1;i<=n;i++){

        if(output[i]==0 && (i%currNum==0 || currNum%i==0)){
            output[i]=currNum;
            solve(n,ans,currNum+1,output);
            output[i]=0; // backtracking
        }

    }

}

int main(){

    int n = 3;
    int ans=0;
    vector<int>output(n+1);

    solve(n,ans,1,output);

    cout<<ans;
    

    return 0;
}