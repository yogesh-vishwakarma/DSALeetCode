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
    ListNode* middleNode2(ListNode* head) {
        ListNode* fastP = head;
        while(fastP->next && fastP->next->next){
            fastP = fastP->next->next;
            head=head->next;
        }
        if(fastP->next)
            return head->next;
        return head;
    }
    
    ListNode* middleNode(ListNode* head) {
        int count = 0;
        ListNode* temp = head;
        while(temp != NULL){
            count++;
            temp = temp -> next;
        }
        
        int c = 0;
        ListNode* temp1 = head;
        while(temp1 != NULL){
            c++;
            if(c == (count/2)+1)
                return temp1;
            temp1 = temp1->next;
        }
        return temp;
    }
};