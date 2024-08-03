#include<iostream>
#include<vector>
using namespace std;

int main(){
    
    int num = 7550;


    string romanSymbols[] = {"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
    int values[] = {1000,900,500,400,100,90,50,40,10,9,5,4,1};


    int i=0;

    string ans;

    while(i<13 && num){

        if(values[i]>num){
            i++;
        }
        else if(values[i]==num){
            ans+=romanSymbols[i];
            break;
        }
        else{
            int sum=0;

            while(true){
                if(sum + values[i] <= num){
                    sum+=values[i];
                    ans+=romanSymbols[i];
                }
                else{
                    break;
                }
            }
            num-=sum;
            i++;

        }

    }

    cout<<ans;

    return 0;
}  