/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode *fastPtr = head, *slowPtr = head;
        while(fastPtr && fastPtr->next){
            fastPtr = fastPtr->next->next;
            slowPtr = slowPtr->next;
            if(fastPtr == slowPtr){
                return true;
            }
        }
        return false;
    }
};