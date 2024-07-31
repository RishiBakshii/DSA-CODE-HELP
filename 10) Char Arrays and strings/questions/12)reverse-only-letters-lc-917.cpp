// we can use built in function isAlpha
// rather than (startChar>=smallA && startChar<=smallz) checking like this

#include<iostream>
using namespace std;

int main(){
    
    string text = "Test1ng-Leet=code-Q!";

    int s=0;
    int e=text.length()-1;

    while(s<e){ 


        int startChar = text[s];
        int endChar = text[e];
        int smallA = 'a';
        int smallz = 'z';
        int captialA = 'A';
        int captialz = 'Z';

        if(! ( (startChar>=smallA && startChar<=smallz) || (startChar>=captialA && startChar<=captialz) ) ){
            s++;
        }
        
        else if(! ( (endChar>=smallA && endChar<=smallz) || (endChar>=captialA && endChar<=captialz) ) ){
            e--;
        }
        else{
            swap(text[s],text[e]);
            s++;
            e--;
        }

    }
    
    cout<<text;

    return 0;
}