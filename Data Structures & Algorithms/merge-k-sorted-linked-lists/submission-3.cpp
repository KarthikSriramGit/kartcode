
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        map<int, int> freq;
        for(ListNode* list : lists){
            while(list){
                freq[list->val]++;
                list = list->next;
            }
        }
        ListNode* dummy = new ListNode();
        ListNode* result = dummy;
        for(auto& iter : freq){
            for(int i = 0; i < iter.second; i++){
                result->next = new ListNode(iter.first);
                result = result->next;
            }
        }
        return dummy->next;
    }
};
