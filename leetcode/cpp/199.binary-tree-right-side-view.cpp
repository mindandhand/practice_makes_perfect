/*
 * @lc app=leetcode id=199 lang=cpp
 *
 * [199] Binary Tree Right Side View
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
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
    vector<int> rightSideView(TreeNode *root)
    {
        vector<int> ret;
        if (root == nullptr)
        {
            return ret;
        }
        std::queue<std::pair<TreeNode *, int>> data_queue;
        data_queue.push(std::make_pair(root, 0));
        int cur_level = 0;
        while (!data_queue.empty())
        {
            auto item = data_queue.front();
            if (item.second == cur_level)
            {
                ret.push_back(data_queue.back().first->val);
                ++cur_level;
            }
            data_queue.pop();
            if (item.first->left != nullptr)
            {
                data_queue.push(make_pair(item.first->left, item.second + 1));
            }
            if (item.first->right != nullptr)
            {
                data_queue.push(make_pair(item.first->right, item.second + 1));
            }
        }
        return ret;
    }
};
// @lc code=end
