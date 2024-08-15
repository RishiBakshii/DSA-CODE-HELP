#include<iostream>
#include<unordered_map>
#include<algorithm>
using namespace std;


int sherlockAndAnagrams(string s){

    unordered_map<string,int> map;
    int n = s.size();

    int anagramaticPairs = 0;

    for(int i=0;i<n;i++){

        for(int j=i;j<n;j++){
            
            string substring = s.substr(i,j-i+1);
            sort(substring.begin(),substring.end());
            map[substring]++;

        }

    }


    // calculating number of pairs

    for(auto element:map){

        int count = element.second;

        int numberOfPairs = (count * (count - 1)) / 2;
        anagramaticPairs+=numberOfPairs;

    }

    return anagramaticPairs;


}

int main(){


    string s = "kkkk";
    cout<<sherlockAndAnagrams(s);
    
    return 0;
}