/*

To handle the situation where num goes out of bound i.e above INT_MAX OR INT_MIN

as we know that INT_MAX => 2147483647

and by doing this  num = num *10 + (int)s[i];
what we are doing is for example there is a string of '123'

now if we really wanna get it in number format we shoudl do something like this
lets say num is 1
num = num * 10 # this will result in 1*10 i.e 10

now we can add the another number in that to make it 12
so 10 + 2 => 12

so that is why this formula is working
num * 10 + (int)nextNumber

But we also have to handle out of range conditions for num where it goes beyond the size of int

INT_MAX => 2147483647

if (num > 214748364) {
    return INT_MAX
}

as this number 214748364 is nothing but 
INT_MAX/10 => 2147483647/10 => 214748364

// so why are we taking INT_MAX/10 as a alert limit?
=> this is because if INT_MAX/10 is this 214748364
=> and we just add a small value into this let say 1
=> 214748364+1 => 214748365
=> and when this forumala will be applied i.e num *10 + (int)s[i];
=> 214748365* 10 will result in 2147483650
=> and this is bigger than the INT_MAX 
=> as INT_MAX is 2147483647 and this number is bigger 2147483650 

now here comes another condition extending this 
if (num > 214748364) {
    return INT_MAX
}

// so above we are checking that if num > INT_MAX/10 
// but what if num is not greater than but equal to INT_MAX/10 i.e num = 214748364
// so if INT_MAX is this 2147483647 and num is this 214748364
// so we are gonna multiply num with 10 i.e fine num*10
// num* 10 => 214748364*10 => 2147483640
// still there is a difference of "7" 
// INT_MAX = 2147483647
// NUM = 2147483640

// and in the formula we know that after multiply with 10 we do add s[i]
num = num *10 + (int)s[i];


// so if this s[i] is greater than 7 then it will make the num greater than INT_MAX

// so this will be our condition for tackling this

if(num==INT_MAX/10 && s[i] > '7'){
    return 
}

// combining both the conditions (final condition)

if(num > INT_MAX/10 || (num==INT_MAX/10 && s[i] > '7')){
    return sign==1?INT_MAX:INT_MIN;
}

*/

#include<iostream>
#include<limits.h>
using namespace std;

int main(){
    
    string s = "helloWorld";

    int num=0,i=0,sign=1;

    // for ignoring the leading space
    while(s[i] == ' '){
        i++;
    }

    // after leading spaces seeing that if there is any sign present
    // if not then we have already taken the sign as 1 ( i.e positive )
    if(i<s.length() && (s[i]== '-' || s[i]=='+')){
        sign = s[i]=='+'?1:-1;
        i++;
    }

    while(i<s.length() && isdigit(s[i])){

        if(num > INT_MAX/10 || (num==INT_MAX/10 && s[i] > '7')){
            return sign==1?INT_MAX:INT_MIN;
        }

        num = num *10 + (int)s[i];
        i++;
    }

    cout<<num*sign;

    return 0;
}