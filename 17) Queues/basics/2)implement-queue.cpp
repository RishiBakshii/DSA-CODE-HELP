#include<iostream>
using namespace std;

class Queue{
    private:
        int* arr;
        int n;
        int front;
        int rear;
    public:
        Queue(int size){
            arr = new int[size];
            front = -1;
            rear = -1;
            n = size;

        }

        void push(int val){
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

        void pop(){
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

        int getFront(){
            if(front==-1){
                cout<<"Queue is empty"<<endl;
                return -1;
            }
            return arr[front];
        }

        int getRear(){
            if(rear==-1){
                cout<<"Queue is empty"<<endl;
                return -1;
            }
            return arr[rear];
        }

        int getSize(){
            if(front==-1 && rear==-1) return 0;
            return rear-front+1;
        }

        bool isEmpty(){
            if(front==-1 && rear==-1) return 1;
            return 0;
        }
};

int main(){

    Queue q(5);

    q.push(10);
    q.push(20);
    q.push(30);

    cout<<q.getSize()<<endl;
    cout<<q.getFront()<<endl;
    cout<<q.getRear()<<endl;

    q.pop();

    cout<<q.getSize()<<endl;
    cout<<q.getFront()<<endl;
    cout<<q.getRear()<<endl;

    q.pop();

    cout<<q.getSize()<<endl;
    cout<<q.getFront()<<endl;
    cout<<q.getRear()<<endl;

    q.pop();

    cout<<endl<<endl;
    cout<<q.getSize()<<endl;
    cout<<q.getFront()<<endl;
    cout<<q.getRear()<<endl;

    
    return 0;
}