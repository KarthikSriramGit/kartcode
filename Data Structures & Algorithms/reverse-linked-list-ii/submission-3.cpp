/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
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
        ListNode* rightAfter = dummy;
        for(int i = 0; i < left - 1; i++){
            leftPrev = leftPrev->next;
        }
        
        ListNode* leftNode = leftPrev->next;
        ListNode* rightNode = leftNode;
        for(int i = 0; i < right - left; i++){
            rightNode = rightNode->next;
        }
        rightAfter = rightNode->next;
        rightNode->next = nullptr;
               
        leftPrev->next = reverseList(leftNode);
        leftNode->next = rightAfter;
        
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