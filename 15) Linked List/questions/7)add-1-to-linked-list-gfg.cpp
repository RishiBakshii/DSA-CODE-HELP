/*
class Solution {
  public:
  
    Node* reverseList(Node* &head){
        
        Node* prev = NULL;
        Node* curr = head;
        
        while(curr!=NULL){
            Node* forward = curr->next;
            curr->next=prev;
            prev=curr;
            curr=forward;
        }
        
        return prev;
        
    }
    
  
    Node* addOne(Node* head) {
        
        head = reverseList(head);
        
        Node* temp = head;
        int carry = 1;
        
        while(temp != NULL) {
            int sum = carry + temp->data;
            //current node me 1 hi digit store hoga, double digit nahi ho skta 
            int digit = sum % 10;
            carry = sum / 10;
            
            temp -> data = digit;
            //move to next node
            //special case, jo last node k liye hoga
            if(temp -> next == NULL && carry != 0) {
                Node* newNode = new Node(carry);
                newNode->next = NULL;
                
                temp->next = newNode;
                temp = newNode;
            }
            //traverse krre h, toh aage toh badhna hi h 
            temp = temp -> next;
        }

        
        //step3: reverseList;
        head = reverseList(head);
        
        return head;
        
    }
};

*/
