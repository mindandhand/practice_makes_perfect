/*
 * @lc app=leetcode id=110 lang=cpp
 *
 * [110] Balanced Binary Tree
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
 public:
  int getHeight(TreeNode* root) {
    if (root == nullptr) {
      return 0;
    }
    if (root->left == nullptr && root->right == nullptr) {
      return 1;
    }
    return 1 + max(getHeight(root->left), getHeight(root->right));
  }
  bool isBalanced(TreeNode* root) {
    if (root == nullptr) {
      return true;
    }
    int result = getHeight(root->left) - getHeight(root->right);
    if (result <= 1 && result >= -1) {
      return isBalanced(root->left) && isBalanced(root->right);
    }
    return false;
  }
};
// @lc code=end
