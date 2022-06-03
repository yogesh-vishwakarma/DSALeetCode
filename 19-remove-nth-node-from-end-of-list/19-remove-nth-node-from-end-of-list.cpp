/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
     ListNode* removeNthFromEnd(ListNode* head, int n) {
       ListNode *f=head;
        ListNode *curr=head;
    
        if(head==NULL) 
            return head;
         
        for(int i=0;i<n;i++){
            f=f->next;
        }
        if(f==NULL){
            head=head->next;
            return head;
        }
        while(f->next!=NULL){
            curr=curr->next;
            f=f->next;
        }
        curr->next=curr->next->next;
        return head;
        
    }
};