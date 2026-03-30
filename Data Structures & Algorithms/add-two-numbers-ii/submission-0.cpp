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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* num1 = reverse(l1);
        ListNode* num2 = reverse(l2);
        int sum = 0;
        ListNode* result = new ListNode(0);
        ListNode* dummy = result;
        while(num1 || num2 || sum){
            if(num1){
                sum += num1->val;
                num1 = num1->next;
            }
            if(num2){
                sum += num2->val;
                num2 = num2->next;
            }
            result->next = new ListNode(sum % 10);
            result = result->next;
            sum /= 10;
        }
        ListNode* newHead = dummy->next;
        delete dummy;
        return reverse(newHead);
    }
    ListNode* reverse(ListNode* head){
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