/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
	void insertElement(vector<vector<int>>& global, TreeNode* root, int level) {
		if (root == nullptr) {
			return;
		}
		if (global.size() <= level) {
			global.push_back(vector<int> {root->val});
		} else {
			global[level].push_back(root->val);
		}
		insertElement(global, root->left, level + 1);
		insertElement(global, root->right, level + 1);
	}
    vector<vector<int>> levelOrder(TreeNode* root) {
   		vector<vector<int>> global;
   		insertElement(global, root, 0);
   		return global;
    }
};
