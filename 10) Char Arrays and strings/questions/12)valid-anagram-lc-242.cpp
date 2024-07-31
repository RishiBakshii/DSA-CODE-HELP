// s => anagram
// t => nagaram

// now i have to check if t is an anagram of s or not

// What is anagram?
// if i have to check if a is an anagram of b then anagram simply means that 
// if a has same number of frequency of all characters as b

// SOlUTIONS

// M1) Sorting O(nlogn)
    // s-> aaagmnr
    // t-> aaagmnr
    // s==t return true 
    // else false

// M2) Counting
    // frequency of each character in s shoudl be the same in t
    // frequency table of s  == frequency table of t
    // return true
    // else false

    // how to make frequence table for strings
    // as we know that ascii table has 256 numbers
    // so we make an array of 256 blocks i.e arr[255]
    // then if we get a char 'a' type cast it to number i.e 97
    // then arr[97]++;
    // so by doing this we can maintain the count for each character frequency


#include<iostream>
using namespace std;

int main(){

    string s = "rat";
    string t = "car";

    // implementing method 2 of solution

    // making frequence table of 256 length
    // why 256?
    // char = 1byte
    // 1byte = 8bits
    // 8bits = 2^8 => 256
    int freqTable[256]={0};

    // calculate char frequency for s
    for(int i=0;i<s.length();i++){
        freqTable[s[i]]++;
    }

    // decrementing the frequcency count as we found the same character
    // so that in the final compare if all the values are 0
    // it means both the strings are anagrams
    for(int i=0;i<t.length();i++){
        freqTable[t[i]]--;
    }

    bool isSame=true;

    // compare the frequencry of s and t
    for(int i=0;i<256;i++){

        if(freqTable[i]!=0){
            isSame=false;
            break;
        }

    }

    cout<<isSame;

    
    return 0;
}