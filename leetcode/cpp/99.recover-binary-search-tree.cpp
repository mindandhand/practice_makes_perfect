/*
 * @lc app=leetcode id=99 lang=cpp
 *
 * [99] Recover Binary Search Tree
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
    TreeNode * firstErrNode = nullptr;
     TreeNode * tmpErrNode = nullptr;
    TreeNode *  preNode= nullptr;
    bool stop = false;
    void inOrderTree(TreeNode *root){
        if(stop == true || root == nullptr){
            return;
        }
        if(root->left != nullptr){
            inOrderTree(root->left);
        }
        if(preNode == nullptr){
            preNode = root;
        } else {
            if(preNode->val > root->val){
                if(firstErrNode == nullptr){
                    firstErrNode = preNode;
                    tmpErrNode = root;
                } else {
                   int tmp = root->val;
                    root->val = firstErrNode->val;
                    firstErrNode->val = tmp;
                    stop = true;
                }
            }
            preNode = root;
        }
        std::cout << root->val;
        if(root->right != nullptr){
            inOrderTree(root->right);
        }
    }
    void recoverTree(TreeNode* root) {      
       inOrderTree(root);
        if(stop == false){
             int tmp = tmpErrNode->val;
                    tmpErrNode->val = firstErrNode->val;
                    firstErrNode->val = tmp;
        }
    }
};
// @lc code=end

