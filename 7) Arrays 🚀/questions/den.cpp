#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> calculateFactorial(int n){

    vector<int>ans;
    ans.push_back(1);

    int carry = 0;

    for(int i=2;i<=n;i++){

        for(int j=0;j<ans.size();j++){
            int product = i * ans[j] + carry;

            if(product>9){
                ans[j] = product%10;
                carry = product/10;
            }
            else{
                ans[j] = product;
            }
        }
        while(carry){
            ans.push_back(carry%10);
            carry /= 10;
        }
    }
    reverse(ans.begin(),ans.end());
    return ans;

}


int main(){
    
    int n=5;
    vector<int> ans = calculateFactorial(5);

    for(auto i : ans){
        cout<<i;
    }

    return 0;
}