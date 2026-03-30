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
bool isSameTree(TreeNode* p, TreeNode* q){
	queue<TreeNode*> q1;
	queue<TreeNode*> q2;
	if(p) q1.push(p);
	if(q) q2.push(q);
	while(!q1.empty() && !q2.empty()){
		TreeNode* node1 = q1.front(); q1.pop();
		TreeNode* node2 = q2.front(); q2.pop();
		if(!node1 && !node2) continue;
		if(!node1 || !node2 || node1->val != node2->val){
			return false;
		}
		q1.push(node1->left);
		q1.push(node1->right);
		q2.push(node2->left);
		q2.push(node2->right);
	}
	return q1.empty() && q2.empty();
}

bool isSubtree(TreeNode* root, TreeNode* subroot){
	queue<TreeNode*> q;
	if(root) q.push(root);
	while(!q.empty()){
		TreeNode* node = q.front(); q.pop();
		if(isSameTree(node, subroot)){
			return true;
		}
		if(node->left) q.push(node->left);
		if(node->right) q.push(node->right);
	}
	return false;
}

};
