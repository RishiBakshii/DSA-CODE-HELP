/*

class Solution {
public:
    ListNode* mergeNodes(ListNode* head) {
        if(!head) return head;
        ListNode* slow = head;
        ListNode* fast = head->next;
        ListNode* newLastNode = 0;
        int sum=0;

        while(fast){
            if(fast->val!=0){
                sum+=fast->val;
            }
            else{
                slow->val=sum;
                sum=0;
                newLastNode=slow;
                slow=slow->next;
            }
            fast=fast->next;
        }

        ListNode* temp = slow;
        while(temp){
            ListNode* nxt = temp->next;
            delete temp;
            temp=nxt;
        };
        newLastNode->next=NULL;
        return head;
    }
};

*/  