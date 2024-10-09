/*

class Solution {
public:

    int getLength(ListNode* head){
        int length = 0;
        ListNode* temp = head;
        while(temp){
            length++;
            temp=temp->next;
        }
        return length;
    }

    ListNode* rotateRight(ListNode* head, int k) {
        if(!head) return nullptr;
        int length = getLength(head);
        int actualRotateK = k%length;
        if(actualRotateK==0) return head;
        int newLastNodePosition = length - actualRotateK - 1;
        ListNode* newLastNode = head;

        for(int i=0;i<newLastNodePosition;i++){
            newLastNode = newLastNode->next;
        }

        ListNode*newHead = newLastNode->next;
        newLastNode->next = 0;

        ListNode* it = newHead;
        while(it->next) it=it->next;
        it->next = head;
        return newHead;
    }
};

*/