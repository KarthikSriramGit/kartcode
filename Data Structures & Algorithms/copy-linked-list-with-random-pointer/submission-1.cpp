class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) return nullptr;
        unordered_map<Node*, Node*> m;
        m[NULL] = NULL;
        Node* curr = head;
        while (curr) {
            m[curr] = new Node(curr->val);
            curr = curr->next;
        }
        curr = head;
        while (curr) {
            m[curr]->next = m[curr->next];
            m[curr]->random = m[curr->random];
            curr = curr->next;
        }
        return m[head];
    }
};