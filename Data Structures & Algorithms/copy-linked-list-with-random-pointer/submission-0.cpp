/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*, Node*> oldtoCopy;
        oldtoCopy[NULL] = NULL;
        Node* curr = head;
        while(curr){
            Node* copy = new Node(curr->val);
            oldtoCopy[curr] = copy;
            curr = curr->next;
        }

        curr = head;
        while(curr){
            Node* copy = oldtoCopy[curr];
            copy->next= oldtoCopy[curr->next];
            copy->random = oldtoCopy[curr->random];
            curr = curr->next;
        }   
        return oldtoCopy[head];
    }
};
