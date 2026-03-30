class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* result = new ListNode(0);  
        result->next = head;

        ListNode* fast = result;
        ListNode* slow = result;

        // Move fast n steps ahead
        for (int i = 0; i < n; ++i) {
            fast = fast->next;
        }

        // Move both until fast reaches the end
        while (fast->next) {
            fast = fast->next;
            slow = slow->next;
        }

        // Remove the nth node
        ListNode* toDelete = slow->next;
        slow->next = slow->next->next;
        delete toDelete;  // free memory

        ListNode* newHead = result->next;
        delete result;    // cleanup dummy
        return newHead;
    }
};
