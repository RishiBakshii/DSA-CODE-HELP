#include<iostream>
#include<vector>
using namespace std;

// void printSubsequences(string str, int i, string output,vector<string> &ans) {
//   //base case
//   if(i == str.length()) {
//     // cout << output << endl;
//     ans.push_back(output);
//     return;
//   }
//   //1 case khud solve karunga
//   char ch = str[i];
//   //include ch 
//   printSubsequences(str,i+1,output + ch,ans);
//   //exclude ch
//   printSubsequences(str,i+1,output,ans);
// }

void printSubsequences(string str, int i, string output,vector<string> &ans) {
  //base case
  if(i == str.length()) {
    ans.push_back(output);
    return;
  }
  char ch = str[i];
  //include
  printSubsequences(str,i+1,output + ch,ans);
  //exclude
  printSubsequences(str,i+1,output,ans);
}

int main(){

  vector<string> ans = {};
  printSubsequences("AAABBC",0,"",ans);
  cout<<ans.size()<<endl;
    
  return 0;
}