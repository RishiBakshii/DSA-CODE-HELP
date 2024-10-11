#include<iostream>
using namespace std;

class Stack{
    public:
        int* arr;
        int size;
        int top1;
        int top2;

    Stack(int capacity){
        arr = new int[capacity];
        size=capacity;
        top1 = -1;
        top2=size;
    }

    void push1(int val){
        if(top2-top1==1){
            cout<<"Stack overflow"<<endl;
        }
        else{
            top1++;
            arr[top1]=val;
        }
    }

    void push2(int val){
        if(top2-top1==1){
            cout<<"Stack overflow"<<endl;
        }
        else{
            top2--;
            arr[top2]=val;
        }
    }

    void pop1(){
        if(top1==-1){
            cout<<"Stack underflow"<<endl;
        }
        else{
            arr[top1]=0;
            top1--;
        }
    }

    void pop2(){
        if(top2==size){
            cout<<"Stack underflow"<<endl;
        }
        else{
            arr[top2]=0;
            top2++;
        }
    }

    void print(){
        cout<<"Printing Stack"<<endl;
        for(int i=0;i<size;i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }

};

int main(){

    Stack s(6);

    s.print();

    s.push1(10);
    s.print();

    s.push2(20);
    s.print();

    s.push1(30);
    s.print();

    s.push2(40);
    s.print();

    s.push1(100);
    s.print();

    s.push2(200);
    s.print();

    s.pop1();
    s.print();
    s.pop1();
    s.print();
    s.pop1();
    s.print();
    s.pop1();
    s.print();

    
    return 0;
}