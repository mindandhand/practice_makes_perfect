/*
 * @lc app=leetcode id=103 lang=cpp
 *
 * [103] Binary Tree Zigzag Level Order Traversal
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
    vector<vector<int>> zigzagLevelOrder(TreeNode *root)
    {
        vector<vector<int>> ret;
        if (root == nullptr)
        {
            return ret;
        }
        std::queue<std::pair<TreeNode *, int>> data_queue;
        data_queue.push(std::make_pair(root, 0));
        int reserver_order = 0;
        while (!data_queue.empty())
        {
            auto item = data_queue.front();
            data_queue.pop();
            if (item.second == ret.size())
            {
                ++reserver_order;
                ret.push_back(vector<int>());
            }
            if (reserver_order % 2 == 0)
                ret[ret.size() - 1].insert(ret[ret.size() - 1].begin(), item.first->val);
            else
                ret[ret.size() - 1].push_back(item.first->val);
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
