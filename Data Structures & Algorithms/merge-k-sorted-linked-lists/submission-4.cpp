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
    ListNode* mergeKLists(vector<ListNode*>& lists){
	if(lists.empty()) return nullptr;
	for(int i = 1; i < lists.size(); i++){
		lists[i] = merge(lists[i], lists[i -1]);
	    }
	return lists.back();
    }
    ListNode* merge(ListNode* l1, ListNode* l2){
        ListNode* dummy = new ListNode();
        ListNode* result = dummy;
        while(l1 && l2){
            if(l1->val < l2->val){
                result->next = l1;
                l1 = l1->next;
            }
            else{
                result->next = l2;
                l2 = l2->next;
            }
            result = result->next;
        }
        if(l1) result->next = l1;
        else if(l2) result->next = l2;
        return dummy->next;
    }
};
