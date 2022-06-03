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
    ListNode* middleNode(ListNode* head) {
        ListNode* fastP = head;
        while(fastP->next && fastP->next->next){
            fastP = fastP->next->next;
            head=head->next;
        }
        if(fastP->next)
            return head->next;
        return head;
    }
};