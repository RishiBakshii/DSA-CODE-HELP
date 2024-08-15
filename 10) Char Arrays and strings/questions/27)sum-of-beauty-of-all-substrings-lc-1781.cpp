#include<iostream>
#include<unordered_map>
#include<limits.h>
using namespace std;

int findBeauty(string s){

    int sumOfBeauty = 0;
    int n = s.size();

    for(int i=0;i<n;i++){
        
        unordered_map<char,int> map;

        for(int j=i;j<n;j++){

            map[s[j]]++;

            int maxi = INT_MIN;
            int mini = INT_MAX;

            for(auto element:map){
                maxi = max(element.second,maxi);
                mini = min(element.second,mini);
            }

            int beauty = maxi-mini;

            if(beauty>0) sumOfBeauty+=beauty;
            
            
        }

    }

    return sumOfBeauty;

}


int main(){
    
    string s = "aabcbaa";

    cout<<findBeauty(s);

    return 0;
}