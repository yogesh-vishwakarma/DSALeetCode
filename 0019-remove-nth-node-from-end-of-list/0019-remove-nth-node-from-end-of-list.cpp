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
        if (head == NULL) {
            return head;
        }
        ListNode* fast = head;
        ListNode* slow = head;

        while (n--) { // Move the fast pointer n positions ahead
            fast = fast->next;
        }

        if (fast == NULL) { // means nth element from end is head
            return head->next;
        }

        // Move both pointers until the fast pointer reaches the end
        while (fast->next) {
            fast = fast->next;
            slow = slow->next;
        }

        // Remove the nth node from the end
        slow->next = slow->next->next;

        return head;
    }
};