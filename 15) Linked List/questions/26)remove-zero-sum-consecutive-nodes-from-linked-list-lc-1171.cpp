/*

class Solution {
public:

    void sanitizeMap(ListNode*curr,unordered_map<int,ListNode*>&mp,int csum){
        int temp = csum;

        while(true){
            temp+=curr->val;
            if(temp==csum) break;
            mp.erase(temp);
            curr=curr->next;
        }
    }

    ListNode* removeZeroSumSublists(ListNode* head) {
        if(!head || (!head->next && head->val==0)) return 0;
        unordered_map<int,ListNode*> mp;
        ListNode* it=head;
        int csum=0;
        while(it){
            csum+=it->val;
            if(csum==0){
                head=it->next;
                mp.clear();
            }
            else if(mp.find(csum)!=mp.end()){
                // if current sum already exists 
                // then it means from previus csum->next till the node till "it" the sum is 0
                sanitizeMap(mp[csum]->next,mp,csum);
                mp[csum]->next=it->next;
            }
            else{
                mp[csum]=it;
            }
            it=it->next;
        }

        return head;
    }
};

*/  