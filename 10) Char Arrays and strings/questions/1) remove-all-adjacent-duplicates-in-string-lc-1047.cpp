#include<iostream>
using namespace std;


string removeDuplicates(string s) {

    int n=s.length();

    if(n==1){
        // if there is only 1 character in string then there are no duplicates
        // hence returning the string itself here
        return s;
    }
    else{
        // if there are more than 1 characters

        // initializing ans string
        string ans = "";

        // traversing throught the provided string i.e s
        for(int i=0;i<n;i++){
            
            if(ans.empty()){
                // if my answer string is empty
                // then pushing the first element from the loop there
                ans.push_back(s[i]);
            }
            else if(s[i]!=ans.back()){
                // as we have pushed the first element in the ans string
                // now we are at let say 2nd element
                // so if the previous element i.e ans.back() is not equal to the current element
                // then we can safely push that to answer 
                // as these two are not duplicates
                ans.push_back(s[i]);
            }
            else if(s[i]==ans.back()){
                // if the current element i.e s[i];
                // is equal to the previously pushed element into the answer string
                // i.e s[i] == ans.back();
                // then it means these both are duplicates and we cannot keep them
                // so we will not push that into answer
                // and will also delete the previously pushed occurence from answer
                ans.pop_back();
            }

        }

        return ans;
    }

    

}


int main(){

    string s="azxxzy";
    removeDuplicates(s);

    return 0;
}