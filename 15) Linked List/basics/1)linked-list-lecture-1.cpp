#include<iostream>
using namespace std;

class Node{

    public:
        int data;
        Node* next;
    
    // constructor
    Node(int data){
        this->data=data;
        this->next=NULL;
    }

};

void printLinkedList(Node* &head){

    cout<<endl;

    Node* temp = head;

    while(temp!=NULL){

        cout<<temp->data<<"->";
        temp = temp->next;

    }
    cout<<"NULL";

    cout<<endl;
}

int getLength(Node* &head){

    Node* temp = head;
    int length=0;

    while(temp!=NULL){
        length++;
        temp=temp->next;
    }

    return length;

}

void insertAtHead(Node* &head, Node* &tail, int data){

    // if linked is empty
    if(head==NULL && tail==NULL){
        Node* newNode = new Node(data);
        head=newNode;
        tail=newNode;
    }
    else{
        // when linked list is not empty
        Node* newNode = new Node(data);
        newNode->next=head;
        head=newNode;
    }

}

void insertAtTail(Node* &head, Node* &tail, int data){

    // if the linked list is empty
    if(head==NULL && tail==NULL){
        Node* newNode = new Node(data);
        head=newNode;
        tail=newNode;
    }
    else{
        // when linked list is not empty
        Node* newNode = new Node(data);
        tail->next = newNode;
        tail=newNode;
    }
}

void insertAtPosition(Node* &head, Node* &tail, int data, int position){


    if(position==1){
        insertAtHead(head,tail,data);
        return;
    }

    else if(position == getLength(head)+1){
        insertAtTail(head,tail,data);
        return;
    }
    
    else{

        int nodeIndex=1;
        Node* temp = head;

        while(nodeIndex!=position-1){
            temp=temp->next;
            nodeIndex++;
        }

        // creating a new node
        Node* newNode = new Node(data);
        Node* nextNode = temp->next;
        temp->next = newNode;
        newNode->next = nextNode;

    }

}

void deleteNodeFromLL(Node* &head, Node* &tail,int position){
    
    // empty check
    if(head==NULL && tail==NULL){
        cout<<"Linked list is empty: no node to delete";
    }

    // single node
    if(head==tail){
        Node* temp = head;
        head = NULL;
        tail = NULL;
        delete temp;
    }

    else{

        if(position==1){
            Node* temp = head;
            head = temp->next;
            temp->next = NULL;
            delete temp;
        }
        else{
            Node* temp = head;
            int nodeIndex = 1;

            while(nodeIndex!=position-1){
                temp = temp->next;
                nodeIndex++;
            }

            Node* nodeToBeDeleted = temp->next;
            Node* nextNode = nodeToBeDeleted->next;
            nodeToBeDeleted->next = NULL;

            temp->next = nextNode;
            delete nodeToBeDeleted;
        }

    }

}

bool searchLinkedList(Node* &head, int target){

    Node* temp = head;

    while(temp!=NULL){
        if(temp->data==target) return true;
        temp = temp->next;
    }

    return false;

}

int main(){

    Node* head = NULL;
    Node* tail = NULL;

    insertAtHead(head,tail,10);
    insertAtHead(head,tail,20);
    insertAtTail(head,tail,30);

    insertAtPosition(head,tail,100,1);
    insertAtPosition(head,tail,200,3);

    insertAtPosition(head,tail,400,6);

    printLinkedList(head);

    deleteNodeFromLL(head,tail,1);

    printLinkedList(head);

    cout<<endl<<"The length is: "<<getLength(head)<<endl<<endl;

    int target = 30;
    cout<<"the target "<<target<<" is "<<searchLinkedList(head,target);


    return 0;
}