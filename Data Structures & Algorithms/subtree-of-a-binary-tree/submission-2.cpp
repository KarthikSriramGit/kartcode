/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (!root) return false;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* node = q.front(); q.pop();
            if(node && node->val == subRoot->val){
                if(isSameTree(node, subRoot)){
                    return true;
                }
            }
            if(node){
                q.push(node->left);
                q.push(node->right);
            }
        }
        return false;
    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
    queue<TreeNode*> q1;
    queue<TreeNode*> q2;
    q1.push(p);
    q2.push(q);
    while(!q1.empty() && !q2.empty()){
        int size = q1.size();
        for(int i = 0; i < size; i++){
            TreeNode* node1 = q1.front(); q1.pop();
            TreeNode* node2 = q2.front(); q2.pop();
            if(node1 == nullptr && node2 == nullptr) continue;
            if((node1 == nullptr || node2 == nullptr) || node1->val != node2->val){
                return false;
            }
            q1.push(node1->left);
            q1.push(node1->right);
            q2.push(node2->left);
            q2.push(node2->right);
        }
    }
    return true;
    }
};
