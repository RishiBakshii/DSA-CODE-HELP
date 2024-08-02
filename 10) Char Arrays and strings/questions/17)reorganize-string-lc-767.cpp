/*

Solutions

Method1 -> priority queue

Method2: greedy
 Find the most occurent character & fit it non-adjacently
// for example aaabc
// a -> 3
// b -> 1
// c -> 1

// so what we can do is
// we can place the most occureing character non adjacently
// like
// a _ a _ a  # we have placed like this so that it is non-adjacent

// now we can fill in the reamaning characters
// a _ a _ a  => a b a c a 

// another test case
// aaab   # length = 4
// a -> 3
// b -> 1

// now filling in the most occurent character
// a _ a _  # as we dont have space left for another a here as we are always placing a at i+1
// so we will have to place a on 1 index

// a a a   # but this here will cause a problem as now it will be adjacently same

// So the conditions are
// 1) if i am placing most occurent character it should be placed in one go
        - if this condition fails then we can return empty string or false

// Approach
// 1) count hash
// 2) try to place the most occurent in one go with 1 index gap , if not possible return "" string
// 3) place other characters with 1 index gap
*/

#include<iostream>
#include<limits.h>
using namespace std;

int main(){
    
    string s = "aab";

    // as our string will only contain lowercase english letters
    // so it varies from (a - z) i.e (97 -> 122);
    // so a total of 26 characters

    // but can we map 26 block array to a-z ??
    // if s[i] = 'a'
    // s[i] - 'a' = 0;
    // so if we need to map a to 0 index of our hash
    // we can do this
    // s[s[i]=-'a'] this will result in 0th index
    // and s[i] can be any character 
    // but this formula
    // s[s[i]-'a'] will always result in a index that is the ascii value for that character
    // and we will be doing  ++ there to count the occurences of a character


    int hash[26] = {0};


    // counting the number of occurences of each character
    for(int i=0;i<s.length();i++){
        hash[s[i]-'a']++;
    }

    // finding the most frequent char
    char mostFrequentChar;
    int maxFreq = INT_MIN;


    for(int i=0;i<26;i++){

        if(hash[i]>maxFreq){
            maxFreq = hash[i];

            // as because i is from 0 to 25
            // so we need to plus 'a' here
            mostFrequentChar = i + 'a';
        }

    }

    int index=0;
    string ans = "";

    while(maxFreq>0 && index<s.length()){

        s[index] = mostFrequentChar;

        maxFreq--;
        index+=2;

    }

    if(maxFreq!=0){
        return false;
    }

    // if we have succesfully placed most freqeunt characters at non-adjacnet places 
    hash[mostFrequentChar - 'a']=0;

    // let's place rest of the characters
    for(int i=0;i<26;i++){

        while(hash[i]>0){
            index = index>=s.length() ? 1 : index;
            s[index] = i + 'a';
            index+=2;
            hash[i]--;
        }

    }


    cout<<s;

    return 0;
}