/*

class Solution {
  public:
    Node* findIntersection(Node* head1, Node* head2) {
        
        Node* ansTail = NULL;
        Node* ansHead = NULL;
        
        unordered_map<int,int> map;
        Node* temphead2 = head2;
        
        while(temphead2!=NULL){
            map[temphead2->data]++;
            temphead2=temphead2->next;
        }
        
        Node* temphead1 = head1;
        
        while(temphead1!=NULL){
            
            if(map[temphead1->data]>0){
                
                if(ansTail==NULL){
                    ansTail = temphead1;
                    ansHead= temphead1;
                }
                else{
                    ansTail->next=temphead1;
                    ansTail=ansTail->next;
                }
                
                map[temphead1->data]--;
            }
            
            temphead1=temphead1->next;
        }
        
        // ansTail->next = NULL;
        if(ansTail) ansTail->next=NULL;
        return ansHead;
        
    }
};

*/