#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;


void solve(string&digits,string&output,int i,vector<string>&ans,unordered_map<char,string>&map){


    // base case
    if(i>=digits.size()){
        ans.push_back(output);
        return;
    }

    string characters = map[digits[i]];

    for(int k=0;k<characters.size();k++){
        output.push_back(characters[k]);
        solve(digits,output,i+1,ans,map);
        output.pop_back();
    }

}

int main(){

    unordered_map<char,string> map;
    map['2']="abc";
    map['3']="def";
    map['4']="ghi";
    map['5']="jkl";
    map['6']="mno";
    map['7']="pqrs";
    map['8']="tuv";
    map['9']="wxyz";

    string digits = "234";
    string output = "";
    vector<string> ans;

    if(digits.size()==1){

        string digitMap = map[digits[0]];

        for(int i=0;i<digitMap.size();i++){
            ans.push_back(string(1,digitMap[i]));
        }

        // return ans;
    }
    else{
        solve(digits,output,0,ans,map);
    }
    
    for(auto i:ans) cout<<i<<endl;


    return 0;
}