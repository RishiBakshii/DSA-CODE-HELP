#include<iostream>
using namespace std;

class Stack{
    public:
        int* arr;
        int size;
        int top;
    
    Stack(int capacity){
        arr = new int[capacity];
        size = capacity;
        top = -1;
    }

    void push(int val){
        if(top==size-1){
            cout<<"Stack Overflow"<<endl;
        }
        else{
            top++;
            arr[top]=val;
        }
    }

    void pop(){
        if(top==-1){
            cout<<"The stack is empty, nothing to pop";
            return;
        }
        else{
            arr[top]=0;
            top--;
        }
    }

    int getSize(){
        return top+1;
    }

    bool isEmpty(){
        if(top==-1) return true;
        return false;
    }

    int getTop(){
        if(top==-1){
            cout<<"The stack is empty";
            return -1;
        }
        else{
            return arr[top];
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
    
    Stack s(5);

    cout<<s.getSize()<<endl;
    cout<<s.isEmpty()<<endl;
    s.pop();
    cout<<endl;
    cout<<s.getTop()<<endl;
    
    s.print();
    s.push(10);

    cout<<s.isEmpty()<<endl;
    cout<<s.getSize()<<endl;
    s.pop();
    cout<<s.getSize()<<endl;
    cout<<s.isEmpty()<<endl;

    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.print();


    s.push(50);
    s.print();

    s.push(60);
    s.print();

    cout<<s.getSize()<<endl;
    cout<<s.getTop()<<endl;
    s.pop();
    cout<<s.getTop()<<endl;

    return 0;
}