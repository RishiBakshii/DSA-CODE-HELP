/*


 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };

class Solution {
public:

    ListNode* getMiddle(ListNode* &slow, ListNode* &fast){

        ListNode* prevOfMiddle = NULL;

        while(fast!=NULL){

            fast=fast->next;

            if(fast!=NULL){
                fast=fast->next;
                prevOfMiddle = slow;
                slow=slow->next;
            }
        };

        return prevOfMiddle;

    }

    ListNode* reverse(ListNode* &prev,ListNode* &curr){

        while(curr!=NULL){
            ListNode* forward = curr->next;
            curr->next=prev;
            prev=curr;
            curr=forward;
        }

        return prev;

    }


    bool isPalindrome(ListNode* head) {

        if(head==NULL) return true;

        if(head->next==NULL) return true;

        ListNode* slow = head;
        ListNode* fast = head;

        ListNode* prevOfMiddle = getMiddle(slow,fast);
        ListNode* middle = slow;

        // cout<<prevOfMiddle->val<<endl;
        // cout<<middle->val<<endl;
        
        // detaching the first half of linked list
        prevOfMiddle->next=NULL;

        // reversing the second half
        ListNode* prev = NULL;
        ListNode* curr = middle;
        ListNode* secondHalfHead =  reverse(prev,curr);

        // comparison between firsthalf and second half elements
        ListNode* firstHalfHead = head;

        while(firstHalfHead!=NULL){
            if(firstHalfHead->val!=secondHalfHead->val) return false;
            firstHalfHead=firstHalfHead->next;
            secondHalfHead=secondHalfHead->next;
        }

        return true;

    }
};
*/