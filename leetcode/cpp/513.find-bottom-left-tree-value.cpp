/*
 * @lc app=leetcode id=513 lang=cpp
 *
 * [513] Find Bottom Left Tree Value
 */
#include <list>
// @lc code=start
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
    int findBottomLeftValue(TreeNode* root) {
           std::list<TreeNode *> cache;
        cache.push_back(root);
        int ret;
        while (cache.size() > 0)
        {
            TreeNode * item = cache.front();
            if (cache.size() == 1)
            {
                ret = item->val;
            }
            if (item->right != nullptr)
            {
                cache.push_back(item->right);
            }
            if (item->left != nullptr)
            {
                cache.push_back(item->left);
            }
            cache.pop_front();
        }
        return ret;
    }
};
// @lc code=end
