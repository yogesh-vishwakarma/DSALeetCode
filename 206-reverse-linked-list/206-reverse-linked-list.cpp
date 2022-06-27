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
    /*easyiest Solution*/
    ListNode* reverseList2(ListNode* head) {
        ListNode* curr = head, * prev = NULL;
        while(curr){
            ListNode* nextPtr = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextPtr;
        }
        return prev;
    }
    
    /*Fastest Solution*/
   ListNode* reverseList(ListNode* head){
        ListNode* recHead = NULL;
        RecRevList(head, recHead);
        return recHead;
    }
    
    ListNode* RecRevList(ListNode* head, ListNode* &revListHead) {
        if(head == NULL)
            return NULL;

        if(head->next == NULL)
            return revListHead = head;
        
        auto temp = RecRevList(head->next, revListHead);
        if(temp == NULL) {
            return revListHead = head;
        }
        head->next = NULL;
        temp->next = head;
        return head;
    }
};