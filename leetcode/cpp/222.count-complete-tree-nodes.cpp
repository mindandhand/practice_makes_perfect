/*
 * @lc app=leetcode id=222 lang=cpp
 *
 * [222] Count Complete Tree Nodes
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
  int countTreeLevel(TreeNode* root) {
    int ret = 0;
    auto tmp = root;
    while (tmp != nullptr) {
      ++ret;
      tmp = tmp->left;
    }
    return ret;
  }
  int rightcountTreeLevel(TreeNode* root) {
    int ret = 0;
    auto tmp = root;
    while (tmp != nullptr) {
      ++ret;
      tmp = tmp->right;
    }
    return ret;
  }
  int countLeafNode(TreeNode* root) {
    if (root == nullptr) {
      return 0;
    }
    if (root->left == nullptr && root->right == nullptr) {
      return 1;
    }
    return countLeafNode(root->left) + countLeafNode(root->right);
  }

  int countBottomLeafNode(TreeNode* root, int totalLevel, int currentLevel) {
    if (root == nullptr) {
      return 0;
    }
    if (root->left == nullptr && root->right == nullptr &&
        totalLevel == currentLevel) {
      return 1;
    }
    return countBottomLeafNode(root->left, totalLevel, currentLevel + 1) +
           countBottomLeafNode(root->right, totalLevel, currentLevel + 1);
  }
  int countNodes(TreeNode* root) {
    if (root == nullptr) {
      return 0;
    }
    int ret = 1;
    int level = countTreeLevel(root);
    int rightLevel = rightcountTreeLevel(root);
    auto tmp = level;
    while (tmp > 1) {
      ret = ret * 2;
      --tmp;
    }

    if (level == rightLevel) {
      return 2 * ret - 1;
    }
    ret = ret + countBottomLeafNode(root, level, 1) - 1;
    return ret;
  }
};
// @lc code=end
