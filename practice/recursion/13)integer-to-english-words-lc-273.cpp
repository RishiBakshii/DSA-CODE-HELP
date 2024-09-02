#include<iostream>
#include<vector>
using namespace std;

string solve(int num,vector<pair<int,string>>&map){


    // base case
    if(num==0) return "Zero";

    string a = "";
    string b = "";
    string c = "";

    auto it = map.end()-1;

    while(it>=map.begin()){

        if(num>=it->first){

            b = it->second;

            if(num>=100) a = solve(num/it->first,map)  + " ";
            
            if(num%it->first!=0) c = " " + solve(num%it->first,map);

            return a + b + c;
        }

        it--;

    }


}

int main(){

    int num = 100000;

    vector<pair<int,string>> map = {
        {1,"One"},
        {2,"Two"},
        {3,"Three"},
        {4,"Four"},
        {5,"Five"},
        {6,"Six"},
        {7,"Seven"},
        {8,"Eight"},
        {9,"Nine"},
        {10,"Ten"},
        {11,"Eleven"},
        {12,"Twelve"},
        {13,"Thirteen"},
        {14,"Fourteen"},
        {15,"Fifteen"},
        {16,"Sixteen"},
        {17,"Seventeen"},
        {18,"Eighteen"},
        {19,"Nineteen"},
        {20,"Twenty"},
        {30,"Thirty"},
        {40,"Forty"},
        {50,"Fifty"},
        {60,"Sixty"},
        {70,"Seventy"},
        {80,"Eighty"},
        {90,"Ninety"},
        {100,"Hundred"},
        {1000,"Thousand"},
        {1000000,"Million"},
        {1000000000,"Billion"},
    };

    string ans = solve(num,map);
    cout<<ans;
    
    return 0;
}