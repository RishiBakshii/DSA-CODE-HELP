#include<iostream>
using namespace std;


bool checkPalindrome(string s,int start,int end){

    // this is a simple function for checking if the string is 
    // pallindromic or not

    while(start<=end){

        if(s[start]==s[end]){
            start++;
            end--;
        }
        else{
            return false;
        }

    }

    return true;

}

bool validPalindrome(string s){

    // calculating the start and end for traversing
    int start=0;
    int end=s.length()-1;

    while(start<=end){

        if(s[start]==s[end]){
            // if both the characters are starting and ending position are same
            // then start++ and end--;
            start++;
            end--;
        }
        else{
            // but if the two characters are not same
            // for example 
            // [ B | B | C ]
            // start is at B
            // end is at C
            // B!=C i.e s[start]!=s[end]
            // so now what we will try is
            // as the question has said we can remove at most 1 charcter and check that
            // if the string is pallidrome or not
            // so first we will to remove the s and then e
            // first removing the e , i.e s -> e-1; [ B | B ]
            // it will return true as this [ B | B ] is pallindromic string
            // now we will try removing the s, i.e [ B | C ]
            // it will return false as this [ B | C ] is not pallendromic

            // so with removed start => [ B | C ] => false
            // with removed end => [ B | B ] => true

            // if any of them is true we can return true i.e the provided string is pallendromic
            // if both are false then we have to return false, as after trying the combination
            // of removing both characters at start and end at each time we are still getting false
            // so that is why we will return false

            // checking for s -> e-1
            bool ans = checkPalindrome(s,start,end-1);

            if(ans){
                // if the first one is true then we will return true
                return true;
            }

            // if the first one is false then we will check for the second combination
            // i.e s+1 -> e
            bool ans2 = checkPalindrome(s,start+1,end);

            // if any of them are true we will return true
            // else false
            return ans || ans2;

        }

    }


}

int main(){
    
    string s="abca";

    cout<<validPalindrome(s);

    return 0;
}