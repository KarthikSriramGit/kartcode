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
    int maxDepth(TreeNode* root) {
        stack<pair<TreeNode*,int>> stck;
        stck.push({root,1});
        int res = 0;
        while(!stck.empty()){
            pair<TreeNode*, int> current = stck.top();
            stck.pop();
            TreeNode* node = current.first;
            int depth = current.second;
            if(node!=nullptr){
                res = max(res,depth);
                stck.push({node->left, depth+1});
                stck.push({node->right, depth+1});
            }
        }
        return res;
    }
};
