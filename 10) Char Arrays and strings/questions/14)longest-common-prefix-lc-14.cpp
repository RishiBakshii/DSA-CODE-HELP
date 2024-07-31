#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;

int findSmallestWord(vector<string>&strs){

    int minIndex=0;

    for(int i=0;i<strs.size();i++){

        if(strs[i].length()<strs[minIndex].length()){
            minIndex=i;
        }

    }

    return minIndex;

}


int main(){
    

    string ans;
    vector<string> strs = {"iron","irotc","iroob"};

    int minIndex = findSmallestWord(strs);

    int lengthOfSmallestWord = strs[minIndex].length();


    for(int i=0;i<lengthOfSmallestWord;i++){

        char prefix = strs[0][i];
        bool isCommonPrefix = true;

        for(int j=1;j<strs.size();j++){

            if(strs[j][i]!=prefix){
                isCommonPrefix=false;
                break;
            }

        }

        if(isCommonPrefix){
            ans.push_back(prefix);
        }
        else{
            break;
        }

    }

    cout<<ans;



    return 0;
}