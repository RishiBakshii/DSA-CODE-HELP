/*

class Solution {
public:
    Node* copyRandomList(Node* head)   {

        if(!head) return 0;

        // step 1: Clone A -> A'
        Node* it = head;
        while(it){
            Node* clonedNode = new Node(it->val);
            clonedNode->next = it->next;
            it->next = clonedNode;
            it = it->next->next;
        }

        // step 2: Assign random links of A' with the helper of A.
        it = head;
        while(it){
            Node* clonedNode = it->next;
            clonedNode->random = it->random ? it->random->next : nullptr;
            it = it->next->next;
        }

        // step 3: Detach A' from A;
        it = head;
        Node* clonedHead = it->next;
        while(it){
            Node* clonedHead = it->next;
            it->next = it->next->next;
            if(clonedHead->next){
                clonedHead->next=clonedHead->next->next;
            }
            it=it->next;
        }

        return clonedHead;
    }  
};

*/