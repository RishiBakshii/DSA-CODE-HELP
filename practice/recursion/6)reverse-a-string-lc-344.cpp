#include<iostream>
#include<vector>
using namespace std;


void reverse(vector<char>&s,int start,int end){

    // base case
    if(start>=end){
        return;
    }

    // handling 1 case
    swap(s[start],s[end]);

    reverse(s,start+1,end-1);

}

int main(){

    vector<char> str = {'h','e','l','l','o'};
    reverse(str,0,str.size()-1);

    for(auto i:str) cout<<i<<" ";

    return 0;
}