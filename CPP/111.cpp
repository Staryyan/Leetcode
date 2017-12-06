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
    int int_max = 1000000;
    int depth(TreeNode* root, int t_depth) {
    	if (root == nullptr) {
    		return int_max;
    	}
    	if (root->left == nullptr && root->right == nullptr) {
    		return t_depth;
    	}
    	return min(depth(root->left, t_depth + 1), depth(root->right, t_depth + 1)); 
    }
    int minDepth(TreeNode* root) {
        if (root == nullptr) {
        	return 0;
        }
        if (root->left == nullptr && root->right == nullptr) {
        	return 1;
        }
        return min(depth(root->left, 2), depth(root->right, 2));
    }
};
