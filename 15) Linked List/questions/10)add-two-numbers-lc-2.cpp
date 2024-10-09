/*

class Solution {
public:

    void insertAtAnsTail(ListNode* &ansHead,ListNode* &ansTail,ListNode* &nodeToInsert){
        if(ansHead==NULL && ansTail==NULL){
            ansHead=nodeToInsert;
            ansTail=nodeToInsert;
        }
        else{
            ansTail->next = nodeToInsert;
            ansTail = nodeToInsert;
        }
    }

    bool isAtEndWithCarryStillLeft(ListNode* h1, ListNode* h2, int &carry){
        if((h1==NULL || h1->next==NULL) && (h2==NULL || h2->next==NULL) && carry!=0){
            return true;
        }
        return false;
    }

    void identifyTheAvailableHeadAndUpdateSumAtTheirLocation(ListNode* h1, ListNode* h2,ListNode* &ansHead, ListNode* &ansTail, int digit){
        if(h1!=NULL){
            h1->val = digit;
            insertAtAnsTail(ansHead,ansTail,h1);
        }
        else{
            h2->val=digit;
            insertAtAnsTail(ansHead,ansTail,h2);
        }
    }

    void solve(ListNode* h1, ListNode* h2, int &carry, ListNode* &ansHead, ListNode* &ansTail){

        if(h1==NULL && h2==NULL) return;

        int num1 = h1 == NULL ? 0 : h1->val;
        int num2 = h2 == NULL ? 0 : h2->val;
        int sum = num1+num2+carry;

        int digit = sum%10;
        carry = sum/10;

        identifyTheAvailableHeadAndUpdateSumAtTheirLocation(h1,h2,ansHead,ansTail,digit);
        
        if(isAtEndWithCarryStillLeft(h1,h2,carry)){
            ListNode* newNode = new ListNode(carry);
            insertAtAnsTail(ansHead,ansTail,newNode);
            return;
        }

        h1 = (h1==NULL || h1->next==NULL) ? NULL : h1->next;
        h2 = (h2==NULL || h2->next==NULL) ? NULL : h2->next;

        solve(h1,h2,carry,ansHead,ansTail);
    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* ansHead = NULL;
        ListNode* ansTail = NULL;
        int carry = 0;
        solve(l1,l2,carry,ansHead,ansTail);
        return ansHead;
    }
};

*/