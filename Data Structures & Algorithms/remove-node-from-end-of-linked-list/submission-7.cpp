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
         ListNode* dummy = new ListNode();
         dummy->next = head; // if the node to delete is the first node
         ListNode* fast = dummy;
         ListNode* slow = dummy;
         for(int i = 0; i < n; i++){
            fast = fast->next;
         }
         while(fast->next){ // move to 1 before
            fast = fast->next;
            slow = slow->next;
         }
         ListNode* todelete = slow->next;
         slow->next = slow->next->next;
         delete todelete;
         return dummy->next;
    }
};
