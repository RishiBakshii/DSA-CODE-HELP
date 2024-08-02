/*
We can further improve this solution by using dp(dynamic programming)

*/

#include<iostream>
using namespace std;

bool isPalindrome(string&str, int start, int end){

    while(start<end){
        
        if(str[start]!=str[end]){
            return false;
        }

        start++;
        end--;

    }

    return true;

}

int main(){

    string s = "babad";
    int n = s.length();
    string ans = "";

    for(int i=0;i<n;i++){

        for(int j=i;j<n;j++){

            if(isPalindrome(s,i,j)){
                string t = s.substr(i,j-i+1);
                ans = t.length()>ans.length()?t:ans;
            }

        }

    }



    return 0;
}