#include<iostream>
using namespace std;


bool isVowel(char ch){

    ch = tolower(ch);

    return (
        ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u'
    );

}

int main(){

    string str = "leetcode";

    int s = 0;
    int e= str.length()-1;

    while(s<e){

        if(isVowel(str[s]) && isVowel(str[e])){
            swap(str[s],str[e]);
            s++;
            e--;
        }
        else if(!isVowel(str[s])){
            s++;
        }
        else{
            e--;
        }

    }
    
    cout<<str;

    return 0;
}