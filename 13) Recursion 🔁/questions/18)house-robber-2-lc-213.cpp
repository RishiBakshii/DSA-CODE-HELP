/*

In this the main catch is if we rob 1st house then we cannot rob last house
And if we rob last house then also we cannot rob first house

so these are the two conditions

1) solve(0,n-2) // here we robbed the first house and skipped the last house

2) solve(1,n-1) // here we robbed the second house and gone till the last

ans will be max (solve(0,n-2), solve(1,n-1))

*/

#include<iostream>
using namespace std;

int main(){

    
    
    return 0;
}