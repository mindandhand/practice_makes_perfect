/*
 * @lc app=leetcode id=95 lang=cpp
 *
 * [95] Unique Binary Search Trees II
 */

// @lc code=start
#include <iostream>
#include <vector>
using namespace std;
// Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
void inOrderPrint(TreeNode *tree)
{
    if (tree != nullptr)
    {
        std::cout << tree->val << ' ';
        inOrderPrint(tree->left);
        inOrderPrint(tree->right);
    }
};

class Solution
{

public:
    TreeNode *copyTree(TreeNode *tree)
    {
        if (tree != nullptr)
        {
            TreeNode *ret = new TreeNode(tree->val);
            ret->left = copyTree(tree->left);
            ret->right = copyTree(tree->right);
            return ret;
        }
        return nullptr;
    }
    vector<TreeNode *> generateChildPath(int start, int end)
    {
        vector<TreeNode *> ret;
        if (start > end)
        {
            ret.push_back(nullptr);
            return ret;
        }
        if (start == end){
            ret.push_back(new TreeNode(start + 1));
            return ret;
        }
        for (auto i = start; i <= end; ++i)
        {
            vector<TreeNode *> left = generateChildPath(start, i - 1);
            vector<TreeNode *> right = generateChildPath(i + 1, end);
            for (auto j = 0; j < left.size(); ++j)
            {
                for (auto k = 0; k < right.size(); ++k)
                {
                    TreeNode *node = new TreeNode(i + 1);
                    node->left = left[j];
                    node->right = right[k];
                    ret.push_back(node);
                }
            }
        }
        return ret;
    }
    vector<TreeNode *> generateTrees(int n)
    {
        vector<TreeNode *> ret;
        ret = generateChildPath(0, n - 1); 
        return ret;
    }
};

void printTreeNodeVec(vector<TreeNode *> &vec)
{
    for (int i = 0; i < vec.size(); i++)
    {
        inOrderPrint(vec[i]);
        std::cout << std::endl;
    }
};

// int main()
// {
//     Solution s;
//     auto ret = s.generateTrees(2);
//     printTreeNodeVec(ret);
//     return -1;
// }
// @lc code=end
