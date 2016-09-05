/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
bool isSymmetricImpl(TreeNode* left, TreeNode* right) {
	if (left->left == right->right) {
		if (left->right == right->left) {
			return true;
		} else if (left->right == nullptr || right->left == nullptr) {
			return false;
		}
		if (left->right->val == right->left->val) {
			return isSymmetricImpl(left->right, right->left);
		}
		return false;
	} else {
		if (left->left == nullptr || right->right == nullptr) {
			return false;
		}
		if (left->left->val != right->right->val) {
			return false;
		}
		if (left->right == right->left) {
			return isSymmetricImpl(left->left, right->right);
		} else if (left->right == nullptr || right->left == nullptr) {
			return false;
		}
		if (left->right->val == right->left->val) {
			return isSymmetricImpl(left->left, right->right) && isSymmetricImpl(left->right, right->left);
		}
		return false;
	}
}
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
    	if (root == nullptr) {
    		return true;
    	}
        if (root->left == root->right) {
        	return true;
        } else if (root->left == nullptr || root->right == nullptr) {
        	return false;
        }
        if (root->left->val != root->right->val) {
        	return false;
        }
        return isSymmetricImpl(root->left, root->right);
    }
};