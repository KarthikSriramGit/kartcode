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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode dummy(0);
        dummy.next = head;
        ListNode* leftPrev = &dummy;
        for(int i = 1; i < left; i++){
            leftPrev = leftPrev->next;
        }
        ListNode* leftNode = leftPrev->next;
        ListNode* rightNode = leftNode;
        for(int i = left; i < right; i++){
            rightNode = rightNode->next;
        }
        ListNode* rightNext = rightNode->next;
        leftPrev->next = nullptr;
        rightNode->next = nullptr;
        ListNode* reversed = reverse(leftNode);
        leftPrev->next = reversed;
        leftNode->next = rightNext;
        return dummy.next;
    }
    ListNode* reverse(ListNode* head){
        ListNode* curr = head;
        ListNode* prev = nullptr;
        while(curr){
            ListNode* temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        return prev;
    }
};