/*
 * @lc app=leetcode id=107 lang=cpp
 *
 * [107] Binary Tree Level Order Traversal II
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
class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> ret;
        if (root == nullptr)
        {
            return ret;
        }
        std::queue<std::pair<TreeNode *, int>> data_queue;
        data_queue.push(std::make_pair(root, 0));
        while (!data_queue.empty())
        {
            auto item = data_queue.front();
            data_queue.pop();
           if (item.second == ret.size())
                ret.insert(ret.begin(), vector<int>());
            ret[0].push_back(item.first->val); 
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

