
/*

class Solution {
  public:
    void insertAtTail(Node* &head,Node* &tail,Node* nodeToBeAttached){
        
        if(head==NULL && tail==NULL){
            head=nodeToBeAttached;
            tail=nodeToBeAttached;
        }
        else{
            tail->next=nodeToBeAttached;
            tail=nodeToBeAttached;
        }
        
    }
  
    // Function to sort a linked list of 0s, 1s and 2s.
    Node* segregate(Node* head) {
        
        
        Node* zeroHead = NULL;
        Node* zeroTail = NULL;
        
        Node* oneHead = NULL;
        Node* oneTail = NULL;
        
        Node* twoHead = NULL;
        Node* twoTail = NULL;
        
        Node* temp = head;
        
        while(temp!=NULL){
            
            Node* toMove = temp;
            temp=temp->next;
            toMove->next=NULL;

            
            if(toMove->data==0){
                insertAtTail(zeroHead,zeroTail,toMove);
            }
            else if(toMove->data==1){
                insertAtTail(oneHead,oneTail,toMove);
            }
            else if(toMove->data==2){
                insertAtTail(twoHead,twoTail,toMove);
            }
        }
        
        
        if(zeroHead!=NULL){
            
            if(oneHead!=NULL){
                zeroTail->next=oneHead;
                oneTail->next=twoHead;
            }
            else{
                zeroTail->next=twoHead;
            }
            
            return zeroHead;
        }
        else{
            if(oneHead!=NULL){
                oneTail->next=twoHead;
                return oneHead;
            }
            else{
                return twoHead;
            }
        }
        
        
    }
};

*/
