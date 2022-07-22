class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        
        if(!head || !head->next) 
            return head;
        
        ListNode* temp=head;
        ListNode *curr=nullptr,*tail=nullptr ;    //curr= node just before the having value less than x
                                                  // tail= first node having value just greater than x
        
        if(head->val>=x){               //checking if smaller nodes will become head or not
            tail=head;                           
        }
        
        
        
        // smaller nodes will come after curr and the last node of these will point to tail
        
        
        
        while(temp){
            if(temp->next and temp->next->val >= x and !curr and !tail){ 
                curr=temp;
                tail=temp->next;
                temp=temp->next;


            } 
            else if(temp->next and temp->next->val < x and (curr || tail)){
                if(curr){
                    curr->next=temp->next;
                    temp->next = temp->next->next;
                    curr=curr->next;
                }
                else{
                    head=temp->next;
                    temp->next=head->next;
                    head->next=temp;
                    curr=head;
                }
            }
            else temp=temp->next;
        }
        
        // pointing the last node to tail
        if(curr)
            curr->next=tail;
        
        return head;
    }
};