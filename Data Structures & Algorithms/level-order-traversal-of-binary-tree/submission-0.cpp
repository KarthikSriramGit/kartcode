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
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> q;
        vector<vector<int>> result;
        q.push(root);
        while(!q.empty()){
            vector<int> vals;
            for(int i = q.size(); i >0;i--){
                TreeNode* node = q.front();
                q.pop();
                if(node){
                    vals.push_back(node->val);
                    q.push(node->left);
                    q.push(node->right);
                }
            }
            if(!vals.empty()){
                result.push_back(vals);
            }
        }
        return result;
    }
};
