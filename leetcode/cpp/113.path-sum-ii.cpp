/*
 * @lc app=leetcode id=113 lang=cpp
 *
 * [113] Path Sum II
 */

#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    vector<vector<int>> pathSum(TreeNode *root, int targetSum)
    {
        vector<vector<int>> ret;
        if (root == nullptrs)
        {
            return ret;
        }
        if (root->val == targetSum && root->left == nullptr && root->right == nullptr)
        {
            ret.push_back(vector<int>(root->val));
            return ret;
        }
        vector<vector<int>> left_ret = pathSum(root->left, targetSum - root->val);
        for (auto vec : left_ret)
        {
            vec.insert(vec.begin(), root->val);
            ret.push_back(vec);
        }
        vector<vector<int>> right_ret = pathSum(root->right, targetSum - root->val);
        for (auto vec : right_ret)
        {
            vec.insert(vec.begin(), root->val);
            ret.push_back(vec);
        }
        return ret;
    }
};
// @lc code=end
