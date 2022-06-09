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
    ListNode* mergeLists(ListNode *A, ListNode *B){
       
        if (A == NULL) return B;
        if (B == NULL) return A;
       
        ListNode *prev = NULL;
        ListNode *p = A;
        ListNode *q = B;
        
        while(p && q){
            if(p->val < q->val){
                prev = p;
                p = p->next;
            }else{
                ListNode *next = q->next;
                
                if(prev == NULL){
                    q->next = A;
                    A = q;
                    prev = q;
                    q = next;
                    continue;
                }
                
                q->next = prev->next;
                prev->next = q;
                prev = q;
                q = next;
            }
        }
        
        if(q){
            prev->next = q;
        }
        
        return A;
    }
    
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size() == 0)
            return NULL;
        
        if(lists.size() == 1){
            return lists[0];
        }
        
        ListNode *head = lists[0];
        
        for(int i = 1 ; i < lists.size() ; i++){
            head = mergeLists(head,lists[i]);
        }
        
        return head;
    }
};