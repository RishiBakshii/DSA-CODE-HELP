#include<iostream>
using namespace std;

int expandAroundCenter(string str,int start, int end){


    // this function is responsible for checking if
    // s==e and then updating the count of palendromic substring
    // and expanding from the center i.e s-- and e++;

    // count variable to maintain the count of palendromic substrings
    int count = 0;

    // getting the length
    int n=str.length();

    // this while loop keep running 
    // if str[start] == str[end]  // means -> if it keeps on finding palindromic substring
    // this while loop also contains bound checking to ensure we stay inside the string
    // i.e start>=0 && end<n
    while(start>=0 && end<n && str[start]==str[end]){

        // if a palindromic substring is found update the count
        count++;

        // expand from center i.e
        // start++
        // end--
        start--;
        end++;
    }

    // returns the count
    return count;

}

int main(){
    
    string s = "abc";

    // getting the length of s
    int n = s.length();

    // for maintaining the odd and even substring count
    int oddSubStringCount = 0;
    int evenSubStringCount = 0;

    // looping over the whole string length
    // to calculate odd and even substrings for every center
    // i.e every ith position
    for(int i=0;i<n;i++){

        // first taking center as i
        int center = i;

        // for odd substrings
        // where s and e needs to be on same position 
        // so passing center and center for both s and e
        // so that both s and e will be on ith position 
        oddSubStringCount+=expandAroundCenter(s,center,center);

        // for even substrings
        // where s is on center and e is on center+1; or e = s+1;
        // so passing the center for s position and center+1 for e position
        // so that s will be on center and e will be on s+1; i.e one block ahead
        evenSubStringCount+=expandAroundCenter(s,center,center+1);
    }

    // the answer would be the sum of all the palindromic substrings
    cout<<oddSubStringCount+evenSubStringCount<<endl;

    return 0;
}  