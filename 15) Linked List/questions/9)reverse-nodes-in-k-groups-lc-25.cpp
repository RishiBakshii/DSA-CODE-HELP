/*
class Solution {
public:

    int getLength(ListNode* &head){
        
        int length = 0;
        ListNode* temp = head;

        while(temp!=NULL){
            length++;
            temp=temp->next;
        }

        return length;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        
        if(head==NULL) return head;

        if(head->next==NULL) return head;

        if(getLength(head)<k) return head;

        ListNode* prev = NULL;
        ListNode* curr = head;
        int position = 0;

        while(position<k){
            ListNode* forward = curr->next;
            curr->next=prev;
            prev=curr;
            curr=forward;
            position++;
        }

        if(curr!=NULL){
            ListNode* recursionAnswer = reverseKGroup(curr,k);
            head->next = recursionAnswer;
        }

        return prev;

    }
};
*/