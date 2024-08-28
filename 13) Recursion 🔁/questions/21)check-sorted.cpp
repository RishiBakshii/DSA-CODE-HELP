#include<iostream>
using namespace std;

bool checkSorted(int arr[], int n, int index) {
  //base case
  if(index == n-1) {
    //single element wala array is treated as SORTED array
    return true;
  }

  bool currAns = false;
  bool recursionKaAns = false;
  //1 case solve karo
  if(arr[index+1] > arr[index]) 
  {
    currAns = true;
  }
  //baaki recursion sambhal lega
  recursionKaAns = checkSorted(arr,n,index+1);

  return (currAns && recursionKaAns);
  // if(currAns == true && recursionKaAns == true)
  //   return true;
  // else
  //   return false;
}

int main(){
    
    return 0;
}