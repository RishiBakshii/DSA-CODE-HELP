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



void solve(Node* head,int currPos, int targetPosition, int &length ,int &ans){
    
    // base case
    if(!head) {
        length=currPos-1;
        return;
    }
    
    
    solve(head->next,currPos+1,targetPosition,length,ans);

    if(length-currPos==targetPosition){
        ans = head->data;
        return;
    }
    
}



int main(){

    Node* node1 = new Node(1);
    node1->next = new Node(2);
    node1->next->next = new Node(1);
    node1->next->next->next = new Node(24);

    Node* head = node1;

    int length  =  0;
    int targetPositionFromTail = 0;
    int ans = -1;

    solve(head,1,targetPositionFromTail,length,ans);

    cout<<ans;
    
    return 0;
}