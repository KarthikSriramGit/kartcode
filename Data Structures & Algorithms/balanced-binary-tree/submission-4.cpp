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
    bool isBalanced(TreeNode* root) {
        return checkHeight(root) != -1;
    }

private:
    // Returns height if subtree is balanced, -1 if unbalanced
    int checkHeight(TreeNode* node) {
        if (!node) return 0;
        
        int leftHeight = checkHeight(node->left);
        if (leftHeight == -1) return -1;  // left subtree already unbalanced
        
        int rightHeight = checkHeight(node->right);
        if (rightHeight == -1) return -1;  // right subtree already unbalanced
        
        if (std::abs(leftHeight - rightHeight) > 1) return -1;  // current node unbalanced
        
        return 1 + std::max(leftHeight, rightHeight);
    }
};