
class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(node == nullptr) return nullptr;
        unordered_map<Node*, Node*> oldToNew;
        oldToNew[node] = new Node(node->val);
        queue<Node*> q;
        q.push(node);
        while(!q.empty()){
            Node* curr = q.front(); q.pop();
            for(Node* nei : curr->neighbors){
                if(oldToNew.find(nei) == oldToNew.end()){
                    oldToNew[nei] = new Node(nei->val);
                    q.push(nei);
                }
                oldToNew[curr]->neighbors.push_back(oldToNew[nei]);
            }
        }
        return oldToNew[node];
    }
};
