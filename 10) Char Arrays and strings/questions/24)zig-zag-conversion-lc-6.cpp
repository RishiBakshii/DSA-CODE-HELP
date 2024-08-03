#include<iostream>
#include<vector>
using namespace std;

int main(){

    string s =  "PAYPALISHIRING";
    int numRows = 3;

    if(numRows==1) cout<<s;

    vector<string>zigzag(numRows);

    int i=0;
    int row=0;
    bool direction = 1; // Top to bottom

    while(true){

        if(direction){
            while(row<numRows && i<s.size()){
                zigzag[row++].push_back(s[i++]);
            }
            row = numRows-2;
        }
        else{
            while(row>=0 && i<s.size()){
                zigzag[row--].push_back(s[i++]);
            }
            row = 1;
        }

        if(i>=s.size()) break;
        direction = !direction;

    }

    string ans="";
    for(int i=0;i<zigzag.size();i++){
        ans+=zigzag[i];
    }

    cout<<ans;

    return 0;
}