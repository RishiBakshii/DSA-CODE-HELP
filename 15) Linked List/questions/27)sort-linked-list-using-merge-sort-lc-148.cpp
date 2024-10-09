/*

class Solution {
public:

    ListNode* findMid(ListNode* head){
        ListNode* slow = head;
        ListNode* fast = head->next;

        while(fast){
            fast=fast->next;
            if(fast){
                fast=fast->next;
                slow=slow->next;
            }
        }

        return slow;
    }

    void insertAtTail(ListNode* &head,ListNode* &tail,ListNode* &nodeToBeInserted){
        if(head==NULL && tail==NULL){
            head = nodeToBeInserted;
            tail = nodeToBeInserted;
        }
        else{
            tail->next = nodeToBeInserted;
            tail=tail->next;
        }
    }

    ListNode* merge(ListNode* list1, ListNode* list2) {

        if(list1==NULL && list2==NULL) return nullptr;

        if(list1 == NULL) return list2;
        if(list2 == NULL) return list1;

        ListNode* ansHead = NULL;
        ListNode* ansTail = NULL;

        ListNode* temphead1 = list1;
        ListNode* temphead2 = list2;

        while(temphead1!=NULL && temphead2!=NULL){
            if(temphead1->val<temphead2->val){
                insertAtTail(ansHead,ansTail,temphead1);
                temphead1=temphead1->next;
            }
            else{
                insertAtTail(ansHead,ansTail,temphead2);
                temphead2=temphead2->next;
            }
        }

        if(temphead1!=NULL) ansTail->next=temphead1;
        if(temphead2!=NULL) ansTail->next=temphead2;

        return ansHead;
    }

    ListNode* sortList(ListNode* head) {
        if(head==NULL || head->next==NULL) return head;

        // Break LL into two halves using mid node
        ListNode* mid = findMid(head);
        ListNode* left=head;
        ListNode* right=mid->next;
        mid->next=NULL;

        // sort RE
        left = sortList(left);
        right = sortList(right);

        // merge both left and right ll
        ListNode* mergedLL = merge(left,right);
        return mergedLL;
    }
};

*/