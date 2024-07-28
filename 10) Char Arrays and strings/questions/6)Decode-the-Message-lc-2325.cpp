#include<iostream>
#include<unordered_map>
using namespace std;

// in this question we have been given a key and message string
// message is encrypted so we have to decrypt the message using key

// steps
// we need to create a subsitution table like this -> https://assets.leetcode.com/uploads/2022/05/08/ex1new4.jpg
// for example if there is a key => "happy boy"
// so we need to create a map like this
// h => a
// a => b
// p => c
// p => c  // as above we already have existing mapping for p
// y => d
// b => e
// o => f
// y => d  // as above we already have existing mapping for y

// and we will also create a mapping for " " space i.e
// " " => " ";


int main(){
    
    // creating an unordered map
    unordered_map<char,char> mapping;

    // creating a mapping for space
    char space = ' ';
    mapping[space]=space;

    // initializing ans string
    string ans = "";

    // this is the key 
    // we have to map this with alphabets
    string key = "the quick brown fox jumps over the lazy dog";

    // this is the encrypted message
    // which we need to decrypt via using a map
    string message = "vkbs bs t suepuv";

    // initializing the alphabet with "a"
    char alphabet = 'a';

    // traversing through whole key to making mapping with alphabets
    for(int i=0;i<key.length();i++){

        // mapping is only created 
        // 1) when the mapping for key[i] is non existent
        //                  and
        // 2) key[i]!=space
        if(mapping.find(key[i])==mapping.end() && key[i]!=space){

            // creating map entry here
            mapping[key[i]]=alphabet;
            
            // after creating an entry with a current key[i] to an alphabet
            // we are moving to next alphabet
            alphabet++;
        }

    }

    // traversing through the message
    for(int i=0;i<message.length();i++){

        // getting the mapped alphabet to current message[i]
        // and pushing that to answer string
        ans.push_back(mapping[message[i]]);
    }
    
    cout<<ans;

    return 0;
}