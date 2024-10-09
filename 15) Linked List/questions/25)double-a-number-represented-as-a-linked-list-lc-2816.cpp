/*

class Solution {
public:

    void solve(ListNode* head,int &carry){
        if(!head) return;
        solve(head->next,carry);
        int mult = (head->val * 2) + carry;
        head->val=mult%10;
        carry = mult/10;
    }
    ListNode* doubleIt(ListNode* head) {
        int carry = 0;
        solve(head,carry);
        if(carry!=0){
            ListNode* newNode = new ListNode(carry);
            newNode->next=  head;
            head=newNode;
        }
        return head;
    }
};

*/