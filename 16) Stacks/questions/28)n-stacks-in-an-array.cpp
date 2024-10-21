#include<iostream>
using namespace std;

class NStack{
    int *a;
    int *top;
    int *next;
    int n;      // no. of stacks
    int size;   // size of main array
    int freeSpot;  // tell free space in main array

    public:
        NStack(int n,int s){
            this->n = n;
            this->size = s;
            this->freeSpot = 0;
            a = new int[s];
            top = new int[n];
            next = new int[s];
            

            // initializing top array with -1 values
            for(int i=0;i<n;i++) top[i]=-1;

            // initializing next array
            for(int i=0;i<s;i++) next[i] = i+1;
            next[s-1] = -1;  // as last index does not have a free space ahead so -1
        }

        // push x into mth stack
        bool push(int x, int m){
            // x is the value that we want to insert
            // m is the number of stack in which we want to push ( this is 1 indexed )
            
            // stack overflow
            if(freeSpot == -1) return false;
            
            // 1. find index
            int index = freeSpot;

            // 2. update freespot
            freeSpot = next[index];

            // 3. insert
            a[index] = x;

            // 4. update next
            next[index] = top[m-1];

            // 5. update top
            top[m-1] = index;

            return true;

        }

        // pop from mth stack
        int pop(int m){

            // stack underflow
            if(top[m-1]==-1) return -1;

            int index = top[m-1];

            top[m-1] = next[index];
            int poppedElement = a[index];
            next[index] = freeSpot;
            freeSpot = index;
            return poppedElement;
        }

        ~NStack(){
            delete[]a;
            delete[]top;
            delete[]next;
        }

};

int main(){

    NStack s(3,6);

    cout<<s.push(10,1) <<endl ;
    cout<<s.push(20,1) <<endl ;
    cout<<s.push(30,1) <<endl ;
    cout<<s.push(40,1) <<endl ;
    cout<<s.push(50,1) <<endl ;
    cout<<s.push(60,1) <<endl ;
    cout<<s.push(70,1) <<endl ;
    cout<<s.pop(1) <<endl ;
    
    return 0;
}