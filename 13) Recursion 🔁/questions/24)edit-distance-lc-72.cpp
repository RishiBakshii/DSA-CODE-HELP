#include<iostream>
#include<limits.h>
using namespace std;


void solve(string&word1,string&word2,int i, int j,int numberOfOperations,int&ans){

    // base case
    if(i>=word1.size()) {
        int remainingCharacters = word2.size()-j;
        ans = min(ans,numberOfOperations+remainingCharacters);
        return;
    }
    if(j>=word2.size()){
        int remainingCharacters = word1.size()-i;
        ans = min(ans,numberOfOperations+remainingCharacters);
        return;
    }


    // same case
    if(word1[i]==word2[j]){
        // we are not doing any operation here
        // just moving forward
        solve(word1,word2,i+1,j+1,numberOfOperations,ans);
    }
    else{
        // if the characters are not same
        // insert operation
        solve(word1,word2,i,j+1,numberOfOperations+1,ans);

        // delete operation
        solve(word1,word2,i+1,j,numberOfOperations+1,ans);

        // replace operation
        solve(word1,word2,i+1,j+1,numberOfOperations+1,ans);
    }

}

int main(){

    string word1 = "horse";
    string word2 = "ros";

    int ans = INT_MAX;

    solve(word1,word2,0,0,0,ans);

    cout<<ans;


    return 0;
}