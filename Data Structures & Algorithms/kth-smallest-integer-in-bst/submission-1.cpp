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
    int kthSmallest(TreeNode* root, int k) {
        vector<int> result;
        preOrder(root, result);
        return result[k -1];
    }
    void preOrder(TreeNode* node, vector<int>& res){
        if(!node){
            return ;
        }
        preOrder(node->left, res);
        res.push_back(node->val);
        preOrder(node->right, res);
    }
};
