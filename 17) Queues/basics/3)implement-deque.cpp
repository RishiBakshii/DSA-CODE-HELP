#include<iostream>
using namespace std;

class Deque{

    private:
        int* arr;
        int front;
        int rear;
        int n;

    public:
        Deque(int size){
            arr = new int[size];
            front = -1;
            rear = -1;
            n = size;
        }

        void pushFront(int val){
            if(front==0){
                cout<<"Queue overflow"<<endl;
            }
            else if(front==-1 && rear == -1){
                front++;
                rear++;
                arr[front]=val;
            }
            else{
                arr[front] == -1;
                front--;
                arr[front]=val;
            }

        }
        void popBack(){
            if(rear==front){
                arr[rear]=-1;
                front = -1;
                rear = -1;
            }
            else if(rear==-1 && front==-1){
                cout<<"Queue underflow";
            }
            else{
                arr[rear]=-1;
                rear--;
            }
        }
        void pushBack(int val){
            // if queue is full
            if(rear == n-1){
                cout<<"Queue overflow"<<endl;
            }
            // if queue is empty
            else if(front==-1 && rear==-1){
                front++;
                rear++;
                arr[rear]=val;
            }
            else{
                rear++;
                arr[rear]=val;
            }
        }
        void popFront(){
            // empty case
            if(front==-1 && rear==-1){
                cout<<"Queue underflow"<<endl;
            }
            else if(front==rear){
                arr[front]=-1;
                front=-1;
                rear=-1;
            }
            else{
                arr[front]=-1;
                front++;
            }
        }
        void print(){
            for(int i=0;i<n;i++) cout<<arr[i]<<" ";
            cout<<endl;
        }
};

int main(){

    Deque dq(5);
    dq.pushFront(10);
    dq.print();
    dq.pushFront(20);
    dq.print();
    dq.pushBack(15);
    dq.print();
    dq.pushBack(35);
    dq.print();
    dq.pushFront(100);
    dq.print();
    dq.popFront();
    dq.print();
    dq.popFront();
    dq.print();
    dq.popFront();
    dq.print();
    dq.popFront();
    dq.print();

    return 0;
}