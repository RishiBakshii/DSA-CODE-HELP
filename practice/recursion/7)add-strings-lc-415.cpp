#include<iostream>
using namespace std;

void solve(string&num1,string&num2,int num1Index,int num2Index,int carry,string&ans){


    // base case
    if(num1Index<0 && num2Index<0){
        return;
    }

    int digit1 = num1Index<0 ? 0 : num1[num1Index] - '0';
    int digit2 = num2Index<0 ? 0 : num2[num2Index] - '0';
    int sum = digit1+digit2+carry; 

    cout<<digit1<<" + "<<digit2<<" + "<<carry<<" = "<<sum<<endl;
    carry=0;


    if(((num1Index<0 && num2Index==0) || (num2Index<0 && num1Index==0)) || (num1Index==0 && num2Index==0)){
        // cout<<"the sum here is "<<sum;
        ans = to_string(sum) + ans;
    }
    else if(sum>9){
        int lastDigit = sum%10;
        ans = to_string(lastDigit) + ans;

        carry = sum/10;
    }
    else{
        ans = to_string(sum) + ans;
    }

    solve(num1,num2,num1Index-1,num2Index-1,carry,ans);

}

int main(){
    

    string num1 = "408";
    string num2 = "5";

    string ans;

    solve(num1,num2,num1.size()-1,num2.size()-1,0,ans);

    cout<<num1<<" + "<<num2<<" = "<<ans;




    return 0;
}