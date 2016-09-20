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
     std::vector<std::vector<int>> v_global;
     void recurse(int layer, TreeNode* node) {
       if (node == nullptr) {
        return;
       }
       if (layer > v_global.size()) {
         v_global.insert(v_global.begin(), vector<int>{node->val});
       } else {
         v_global[v_global.size() - layer].push_back(node->val);
       }
       recurse(layer+1, node->left);
       recurse(layer+1, node->right);
     }
     vector<vector<int>> levelOrderBottom(TreeNode* root) {
          recurse(1, root);
          return v_global;
     }
 };
