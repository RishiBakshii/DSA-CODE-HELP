#include<iostream>
using namespace std;

class Node{
    public:
        int data;
        Node* prev;
        Node* next;
    
    Node(int data){
        this->data=data;
        this->prev=NULL;
        this->next=NULL;
    }
};

void printLinkedList(Node* &head){

  Node* temp = head;
  while(temp!= NULL) {
    cout << temp->data << "->";
    temp = temp ->next;
  }
  cout << "NULL"<<endl;
}

void printReverseLinkedList(Node* &tail){

    cout<<endl;

    Node* temp = tail;

    while(temp!=NULL){
        cout<<temp->data<<"->";
        temp=temp->prev;
    }
    cout<<"NULL"<<endl;

}

void insertAtHead(Node* &head, Node* &tail, int data){

    if(head==NULL && tail==NULL){
        // if the linked list is empty
        Node* newNode = new Node(data);
        head=newNode;
        tail=newNode;
    }

    else{
        // if the linked list is not empty
        Node* newNode = new Node(data);
        newNode->next=head;
        head->prev=newNode;
        head=newNode;
    }

}

void insertAtTail(Node* &head, Node* &tail, int data){

    // if linked list is empty
    if(head==NULL && tail==NULL){
        Node* newNode = new Node(data);
        head=newNode;
        tail=newNode;
    }
    else{
        // when the linked list is not empty
        Node* newNode = new Node(data);
        newNode->prev=tail;
        tail->next=newNode;
        tail=newNode;
    }

}

int getLength(Node* &head){

    int length = 0;
    Node* temp = head;

    while(temp!=NULL){
        length++;
        temp=temp->next;
    }

    return length;
}

void insertAtPosition(Node* &head, Node* &tail, int position, int data){

    if(position==1){
        insertAtHead(head,tail,data);
    }
    else if(position==getLength(head)+1){
        insertAtTail(head,tail,data);
    }
    else{

        Node* backwardNode = head;
        int currentNode = 1;

        while(currentNode!=position-1){
            backwardNode=backwardNode->next;
            currentNode++;
        }

        Node* newNode = new Node(data);
        Node* forwardNode = backwardNode->next;

        backwardNode->next = newNode;
        newNode->prev=backwardNode;

        newNode->next = forwardNode;
        forwardNode->prev = newNode;

    }

}

bool searchElement(Node* &head, int target){

    Node* temp = head;
    while(temp!=NULL){
        if(temp->data==target) return true;
        temp=temp->next;
    }
    return false;
}

void deleteFromPosition(Node* &head, Node* &tail, int position){

    // empty case
    if(head==NULL && tail==NULL){
        cout<<"Nothing to delete";
    }
    else if(head==tail){
        Node* temp = head;
        head=NULL;
        tail=NULL;
        delete temp;
    }
    else if(position==1){
        // deleting the head node
        Node* nodeNextToHead = head->next;
        head->next=NULL;
        nodeNextToHead->prev=NULL;

        Node* temp = head;
        head=nodeNextToHead;
        delete temp;
    }
    else if(position==getLength(head)){
        // deleting the tail node
        Node* nodeBeforeTailNode = tail->prev;
        nodeBeforeTailNode->next=NULL;
        tail->prev=NULL;

        Node* temp = tail;
        tail=nodeBeforeTailNode;
        delete temp;
    }
    else{
        // deleting any other node in between
        Node* backwardNode = head;
        int currentNode = 1;

        while(currentNode!=position-1){
            backwardNode=backwardNode->next;
            currentNode++;
        }

        Node* nodeToBeDeleted = backwardNode->next;
        Node* forwardNode = nodeToBeDeleted->next; 

        backwardNode->next = forwardNode;
        forwardNode->prev = backwardNode;

        nodeToBeDeleted->next=NULL;
        nodeToBeDeleted->prev=NULL;

        delete nodeToBeDeleted;
    }

}

int main(){

    Node* head = NULL;
    Node* tail = NULL;

    insertAtHead(head,tail,10);
    insertAtHead(head,tail,20);
    insertAtHead(head,tail,50);

    insertAtTail(head,tail,30);
    insertAtTail(head,tail,40);

    insertAtPosition(head,tail,3,100);

    deleteFromPosition(head,tail,1);
    deleteFromPosition(head,tail,5);
    deleteFromPosition(head,tail,3);


    printLinkedList(head);
    cout<<"The length is: "<<getLength(head)<<endl;

    int targetElement = 100;
    cout<<endl<<"The target element "<<targetElement<<" is "<<searchElement(head,targetElement)<<endl;

    
    // printReverseLinkedList(tail);
    
    return 0;
}