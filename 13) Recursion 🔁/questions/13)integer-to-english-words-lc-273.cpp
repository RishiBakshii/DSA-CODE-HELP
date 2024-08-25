#include<iostream>
#include<vector>
using namespace std;

string solve(int num,vector<pair<int,string>>&map){


    // base case
    if(num==0) return "Zero";

    // finding from which our num is just greater
    for(auto it:map){

        if(num>=it.first){

            string a = "";

            if(num>=100){
                a = solve(num/it.first,map) + " ";
            }

            string b = it.second;

            string c = "";

            if(num%it.first!=0){
                c = " " + solve(num%it.first,map);
            }

            return a+b+c;
        }

    }


}

int main(){
    
    vector<pair<int,string>> map={

        {1000000000,"Billion"},
        {1000000,"Million"},
        {1000,"Thousand"},
        {100,"Hundred"},
        {90,"Ninety"},
        {80,"Eight"},
        {70,"Seventy"},
        {60,"Sixty"},
        {50,"Fifty"},
        {40,"Forty"},
        {30,"Thirty"},
        {20,"Twenty"},
        {19,"Nineteen"},
        {18,"Eighteen"},
        {17,"Seventeen"},
        {16,"Sixteen"},
        {15,"Fifteen"},
        {14,"Fourteen"},
        {13,"Thirteen"},
        {12,"Twelve"},
        {11,"Eleven"},
        {10,"Ten"},
        {9,"Nine"},
        {8,"Eight"},
        {7,"Seven"},
        {6,"Six"},
        {5,"Five"},
        {4,"Four"},
        {3,"Three"},
        {2,"Two"},
        {1,"One"},

    };

    int num =245;
    cout<<solve(num,map);

    return 0;
}