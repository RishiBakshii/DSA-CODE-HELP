#include<iostream>
using namespace std;

int main(){
    
    string haystack = "sadbutsad";
    string needle = "sad";


    int s=0;
    int e=haystack.length()-1;
    int ans=-1;

    while(s<e){

        if(haystack[s]!=needle[0]){
            s++;
        }
        else if(haystack[e]!=needle[needle.length()-1]){
            e--;
        }
        else if(haystack[s]==needle[0] && haystack[e]==needle[needle.length()-1]){
            // here we need to compare
            if(needle.compare(haystack.substr(s,needle.length()))==0){
                // if the word matches 
                // then store the first index of this answer
                ans=s;

                // and then look behind further
                // as we need to find the first most occurence
                e--;
            }
            else{
                // if the word is not found then go in forward direction
                // so s++;
                s++;
            }
        }

    }
    cout<<ans;

    return 0;
}