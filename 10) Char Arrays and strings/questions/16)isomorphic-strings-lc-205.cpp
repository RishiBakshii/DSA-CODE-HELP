#include<iostream>
using namespace std;

int main(){

    string s = "foo";
    string t = "bar";

    int hash[256] = {0};
    bool tCharMapped[256] = {0};

    for(int i=0;i<s.length();i++){

        if(hash[s[i]]==0 && tCharMapped[s[i]]==0){
            hash[s[i]]=t[i];
            tCharMapped[s[i]]=1;
        }

    }

    bool ans = 1;

    for(int i=0;i<s.length();i++){

        if(hash[s[i]]!=t[i]){
            ans=0;
            break;
        }

    };

    cout<<ans;

    return 0;
}