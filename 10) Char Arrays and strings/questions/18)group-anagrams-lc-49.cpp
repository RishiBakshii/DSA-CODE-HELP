/*

SOlUTIONS

Method 1:

apply sorting on each word
// strs = ["eat","tea","tan","ate","nat","bat"]
// strs = ["aet","aet","ant","aet","ant","abt"]  #after sorting

// now we can group them like this using map
// [["aet","aet","aet"],["ant","ant"],"abt"]


// we will store the sorted values of strings in keys
// and values will be the original version of them

key  |  value 
aet  |  [eat,tea,ate]     
ant  |  [tea,nat]
abt  |  [bat]


Method 2:
In this method we will not applying sorting

key(hash[256])  |  value 
e - 1  |  [eat,tea,ate]     
a - 1  |
t - 1  |

t - 1  |  [tan]     
n - 1  |
a - 1  |


*/

#include<iostream>
#include<map>
#include<vector>
#include<array>
#include<algorithm>
using namespace std;

array<int,256> hashed(string s){

    array<int,256> hash = {0};

    for(int i=0;i<s.length();i++){

        hash[s[i]]++;

    }

    return hash;
}

int main(){
    
    // Method 1
    // map<string,vector<string>> mp;

    // vector<string> strs = {"eat","tea","tan","ate","nat","bat"};

    // for(auto str:strs){
    //     string s = str;
    //     sort(s.begin(),s.end());
    //     mp[s].push_back(str);
    // }

    // vector<vector<string>> ans;

    // auto it = mp.begin();

    // while(it!=mp.end()){
    //     ans.push_back(it->second);
    // }

    // Method 2
    map<array<int,256>,vector<string>> mp;
    vector<vector<string>> ans;

    vector<string> strs = {"eat","tea","tan","ate","nat","bat"};

    for(auto str:strs){
        mp[hashed(str)].push_back(str);
    }
    
    auto it = mp.begin();

    while(it!=mp.end()){
        ans.push_back(it->second);
        it++;
    }



    return 0;
}