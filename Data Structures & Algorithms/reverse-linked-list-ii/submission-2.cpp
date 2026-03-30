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
        if(left == right){
            return head;
        }
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* leftPrev = dummy;
        for(int i = 1; i < left; i++){
            leftPrev = leftPrev->next;
        }
        
        ListNode* leftNode = leftPrev->next;
        ListNode* fast = leftNode;
        for(int i = 0; i < right - left; i++){
            fast = fast->next;
        }
        
        ListNode* rightNode = fast;
        ListNode* rightNext = rightNode->next;
        rightNode->next = nullptr;
        
        ListNode* reversedHead = reverseList(leftNode);
        
        leftPrev->next = reversedHead;
        leftNode->next = rightNext;
        
        return dummy->next;
    }
    ListNode * reverseList(ListNode* head){
        ListNode* prev = nullptr;
        ListNode* curr = head;
        while(curr){
            ListNode* temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        return prev;
    }
};