#include<iostream>
using namespace std;


void solve(string&s,int index,char target,int &ansIndex){


    // BASE CASE
    if(index==-1){
        return;
    }

    if(s[index]==target){
        ansIndex = index;
        return;
    }

    solve(s,index-1,target,ansIndex);

}

int main(){
    
    string s = "iasdfasdf";
    char ch = 'i';
    int ansIndex = -1;
    solve(s,s.size()-1,ch,ansIndex);

    cout<<ch<<" is present at "<<ansIndex;

    return 0;
}