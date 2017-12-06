/*
**
  Definition for a binary tree node.
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };
 */
class Solution {
public:
   	TreeNode* merge(TreeNode* T1, TreeNode* T2) {
   		if (T1 == NULL) {
   			return T2;
   		}
   		if (T2 == NULL) {
   			return T1;
   		}
   		TreeNode* tmp = new TreeNode(0);
   		tmp->val = T1->val + T2->val;
   		tmp->left = merge(T1->left, T2->left);
   		tmp->right = merge(T1->right, T2->right);
   		return tmp;
    }
};