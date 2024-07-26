#include<iostream>
using namespace std;

string removeAllOccurrencesOfSubtringFromString(string s, string substring) {
        
        // first of all finding the starting index of the matching substring
        // s.find(substring) will return us the index from where the substring is starting to match
        int result = s.find(substring);

        // calulating the length of the substring
        // it will help us in determining to erase till where?
        // i.e from result(startingIndex) to how many indexes we have to erase
        int patternLength = substring.length();
        
        // this loop will run until the pattern is being found in the string
        while(result!=string::npos){

            // if the pattern is found 
            // then we will erase it from string
            // from starting index of the pattern i.e result to patternLenght
            s.erase(result,patternLength);

            // after erasing the pattern
            // now we will again search for that in the string
            // so if there is any , it will be found
            result = s.find(substring);
        }

        return s;

}

int main(){
    


    return 0;
}