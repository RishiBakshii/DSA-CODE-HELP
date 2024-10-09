#include<iostream>
using namespace std;

class Node{
    public:
        Node* prev;
        Node* child;
        Node* next;
        int val;

    Node(int val){
        this->val=val;
        this->prev=NULL;
        this->child=NULL;
        this->next=NULL;
    }
};

void printDoublyMultilevelLinkedList(Node* head, Node* &ansTail) {
    // Base case
    if (head == NULL) return;

    Node* temp = head;

    while (temp != NULL) {
        // Link current node to the answer list
        ansTail->next = temp;
        ansTail = ansTail->next;

        // If the node has a child, recurse
        if (temp->child) {
            printDoublyMultilevelLinkedList(temp->child, ansTail);
        }

        // Move to the next node
        temp = temp->next;
    }
}



void printLinkedList(Node* &head){

    cout<<"Answer linked list "<<endl;
    Node* temp = head;

    while(temp!=NULL){
        cout<<temp->val<<"->";
        temp=temp->next;
    }
    cout<<"NULL";
}

int main() {
    Node* head = NULL;

    Node* oneNode = new Node(1);
    Node* twoNode = new Node(2);

    head = oneNode;
    oneNode->next = twoNode;

    Node* threeNode = new Node(3);
    twoNode->next = threeNode;

    // Create children for the node 3
    Node* child1 = new Node(7);
    Node* child2 = new Node(8);
    threeNode->child = child1;
    child1->next = child2;

    // Create grandchildren for node 8
    Node* grandchild1 = new Node(11);
    Node* grandchild2 = new Node(12);
    child2->child = grandchild1;
    grandchild1->next = grandchild2;

    // Create nodes 4, 5, 6
    Node* fourNode = new Node(4);
    Node* fiveNode = new Node(5);
    Node* sixNode = new Node(6);

    threeNode->next = fourNode;
    fourNode->next = fiveNode;
    fiveNode->next = sixNode;

    Node* ans = new Node(-1);
    Node* ansHead = ans;
    Node* ansTail = ans;

    printDoublyMultilevelLinkedList(head, ansTail);
    cout << "NULL" << endl;

    printLinkedList(ansHead->next);
    cout << endl << "ans tail at: " << ansTail->val << endl;

    return 0;
}
