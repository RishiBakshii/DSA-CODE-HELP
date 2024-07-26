#include<iostream>
using namespace std;

int main(){

    string s = "deeedbbcccbdaa";

    // cout<<s.substr(1,3);

    int k=3;
    int n=s.length();

    for (int i = 0; i < n; i++){

        string substring = s.substr(i,k);
        string compairsonString(k,substring[0]);

        if(substring.compare(compairsonString)==0){
            // if k duplicate elements found
            
        }
        else{

        }

    }

    cout<<s;
    


    return 0;
}