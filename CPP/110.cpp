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
	int depth(TreeNode* root) {
		if (root == nullptr) {
			return 0;
		}
		return 1 + max(depth(root->left), depth(root->right));
	}
	bool balance(int a, int b) {
		return (a - b <= 1) && (b - a <= 1);
	}
    bool isBalanced(TreeNode* root) {
        if (root == nullptr) {
        	return true;
        } else {
        	if (balance(depth(root->left), depth(root->right))) {
        		return isBalanced(root->left) && isBalanced(root->right);
        	} else {
        		return false;
        	}
        }
    }
};
