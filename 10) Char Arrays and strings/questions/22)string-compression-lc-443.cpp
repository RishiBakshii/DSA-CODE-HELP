#include<iostream>
#include<vector>
using namespace std;

int main(){

    vector<char> s = {'a'};

    int index = 0;
    int count = 1;
    char prev = s[0];

    for(int i=1;i<s.size();i++){


        if(s[i]==prev){
            count++;
        }
        else{
            s[index++] = prev;
            if(count>1){
                s[index++]=count;
            }

            prev = s[i];
            count=1;
        }

    }




    return 0;

}