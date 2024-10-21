#include<iostream>
using namespace std;

class CircularQueue{
    private:
        int* arr;
        int front;
        int rear;
        int n;

    public:
        CircularQueue(int size){
            arr = new int[size];
            front = -1;
            rear = -1;
            n = size;
        }

        void push(int val){
            //4 cases: Overflow, first elemnt, circualr nature, normal flow
            if(front == -1 && rear == -1){
                rear++;
                front++;
                arr[rear]=val;
            }
            else if((rear == n-1 && front == 0) || (rear-front==-1)){
                cout<<"Queue overflow"<<endl;
            }
            else if(rear==n-1){
                rear=0;
                arr[rear]=val;
            }
            else{
                rear++;
                arr[rear]=val;
            }
        }
        void pop(){
            if(front == -1 && rear == -1){
                cout<<"Queue underflow"<<endl;
            }
            else if(front == rear){
                arr[front]=-1;
                front = -1;
                rear = -1;
            }
            else{
                arr[front]=-1;
                front++;
            }
        }
        int getFront(){
            if(front==-1) return -1;
            return arr[front];
        }
        int getRear(){
            if(rear==-1) return -1;
            return arr[rear];
        }
        
        int getSize(){
            if(rear>front){
                return rear-front+1;
            }
            else{
                return (n-front) + (rear + 1);
            }
        }
        
        bool isEmpty(){
            if(front==-1 && rear==-1) return true;
            return false;
        }
        void print(){
            for(int i=0;i<n;i++) cout<<arr[i]<<" ";
            cout<<endl;
        }
};

int main(){

    CircularQueue q(5);

  q.push(10);
  q.print();
  q.push(20);
  q.print();
  q.push(30);
  q.print();
  q.push(40);
  q.print();
  q.push(50);
  q.print();
  q.push(60);
  q.print();

    q.pop();
  q.print();

    q.pop();
  q.print();

    q.push(100);
  q.print();

    q.push(101);
  q.print();

    cout << q.getSize() << endl;
  cout << q.isEmpty() << endl;
  cout << q.getFront() << endl;
  
    
    return 0;
}