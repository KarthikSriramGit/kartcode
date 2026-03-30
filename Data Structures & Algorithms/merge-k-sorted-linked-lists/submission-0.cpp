class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        map<int, int> freq;
        for (auto list : lists) {
            while (list) {
                freq[list->val]++;
                list = list->next;
            }
        }

        ListNode* dummy = new ListNode(0);
        ListNode* curr = dummy;

        for (auto& iter : freq) {
            for (int i = 0; i < iter.second; ++i) {
                curr->next = new ListNode(iter.first);
                curr = curr->next;
            }
        }

        ListNode* result = dummy->next;
        delete dummy;
        return result;
    }
};
