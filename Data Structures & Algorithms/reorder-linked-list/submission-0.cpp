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
    ListNode * reverse(ListNode* head){
        ListNode * curr = head;
        ListNode * prev = nullptr;
        while(curr){
            ListNode * temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        return prev;
    }
    void reorderList(ListNode* head) {
        ListNode * fast = head;
        ListNode * slow = head;
        while(fast->next && fast->next->next){
            fast = fast->next->next;
            slow = slow->next;
        }
        ListNode * first = head;
        ListNode * second = reverse(slow->next);
        slow->next = nullptr;
        while(second){
            ListNode * p1 = first->next;
            ListNode * p2 = second->next;
            first->next = second;
            second->next = p1;
            first = p1;
            second = p2;
        }
    }
};
