/*

In the case of strings they are sorted Lexicographically
that means if there is vector of strings 
["3","30","34","5","9"]
and if we wanna sort them in descending order so
they will be sorted based on the first character of each string first
for ex => 30 will be sorted based on it's 3 not the full 30 and
34 will be sorted based on it's 3 not the full 34

// so will be sorted like
["9","5,","3","3","3"]

// so if we talk about ["3","30","34"]
// it be sorted based on dictionary like style
// first of all 3 will be sorted like this based on 1 character
// ["3","3","3"]
// now based on second digits it will be sorted in descending order
// ["34","30","3"]


// for we see the full lexicographically sorting of this
["3","30","34","5","9"]

// first of all it will be sorted based on 1st character
["9","5","3","3","3"]

// now it be again be sorted based on 2nd character
["9","5","34","30","3"]

// but here is the problem in this part ["30","3"]
// as first it is sorted according to first character i.e 3 
// ["3","3"]
// so based on second charcter it puts 30 forward
["30","3"]  but 303 is smaller than 330
so it should be sorting like ["3","30"] so that we 330

// so we'll have to fix that
// we need to tell that you should count 3 as bigger rather than 30 based on lexographiclyy sorting

*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool mycomp(string a,string b){

    // here we are saying that

    // first try the combination of string addition with a+b i.e t1
    string t1 = a+b;
    
    // then try the combination of string addition with b+a i.e t2
    string t2 = b+a;

    // if t1 is greater than t2 it means a>b 
    // if t2 is greater than t1 it means b>a
    // and it will be treated accordingly while sorting
    return t1>t2;

}

int main(){
    
    vector<int> nums = {3,30,34,5,9};

    vector<string>snums;
    string ans;

    for(auto num:nums){
        snums.push_back(to_string(num));
    }

    sort(snums.begin(),snums.end(),mycomp);

    if(snums[0]=="0"){
        ans="0";
    }
    else{
        for(auto str:snums){
            ans+=str;
        }
    }

    cout<<ans;

    return 0;
}
