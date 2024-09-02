#include<iostream>
using namespace std;

// TC => O(2^n)
// SC => n+1 => O(n)

bool solve(string s,int si,string p,int pi){


    // base case
    if(si==s.size() && pi==p.size()){
        return true;
    }

    if(si==s.size() && pi<p.size()){

        // we need to check if p contains only * or not

        // as if p contains only * then we can match them with empty sequence or basically mark them as null
        // but if not then we have to return false

        while(pi<p.size()){
            if(p[pi]!='*') return false;
            pi++;
        }

        return true;

    }


    if(s[si]==p[pi] || p[pi]=='?'){

        // it matches, go forward
        return solve(s,si+1,p,pi+1);

    }
    else if(p[pi]=='*'){

        // now here comes two cases

        // first we will take the * as null or empty
        bool case1 = solve(s,si,p,pi+1);

        // then take the * to engulf one character
        bool case2 = solve(s,si+1,p,pi);

        return case1 || case2;
    }

    return false;

}

int main(){
    
    string s  = "cb";
    string  p = "?a";

    cout<<solve(s,0,p,0);

    return 0;
}