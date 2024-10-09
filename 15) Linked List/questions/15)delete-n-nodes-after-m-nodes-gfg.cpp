#include<iostream>
using namespace std;

class Node{
    public:
        int data;
        Node* next;

    Node(int data){
        this->data=data;
        this->next=NULL;
    }
};

void print(Node* head){
    Node* temp = head;

    while(temp!=NULL){
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<"NULL";
}

void solve(Node* &head, int n, int m){

    if(!head) return;
    
    // initializing an iterator
    Node* it = head;

    for(int i=0;i<m-1;i++){
        if(!it) return;
        it=it->next;
    }

    Node * mthNode = it;
    if(!mthNode) return;

    // nth node
    Node* nthNode = mthNode->next;
    it = nthNode;

    for(int i=0;i<n;i++){
        if(!it) return;
        Node* forward = it->next;
        it->next = NULL;
        delete it;
        it=forward;
    }

    // making connection
    mthNode->next = it;

    solve(it,n,m);

}

int main(){

    Node* node1 = new Node(1);
    Node* head = node1;
    node1->next=new Node(15);
    node1->next->next =  new Node(12);
    node1->next->next->next =  new Node(9);
    node1->next->next->next->next =  new Node(16);
    node1->next->next->next->next->next =  new Node(6);
    node1->next->next->next->next->next->next =  new Node(13);
    node1->next->next->next->next->next->next->next =  new Node(5);
    node1->next->next->next->next->next->next->next->next =  new Node(9);
    node1->next->next->next->next->next->next->next->next->next =  new Node(8);
    node1->next->next->next->next->next->next->next->next->next->next =  new Node(9);

    int m = 1; // skip m nodes
    int n = 3; // delete n nodes

    cout<<"Before solving"<<endl;
    print(head);
    cout<<endl;

    cout<<"After solving"<<endl;
    solve(head,n,m);
    print(head);

    return 0;
}