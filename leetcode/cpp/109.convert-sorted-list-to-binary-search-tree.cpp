/*
 * @lc app=leetcode id=109 lang=cpp
 *
 * [109] Convert Sorted List to Binary Search Tree
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 */
 struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
 
/**
 * Definition for a binary tree node.
 */
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
 // 1, 2, 3, 4,5, 6
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        if(head == nullptr) return nullptr;
        if(head->next == nullptr){
            return new TreeNode(head->val);
        }  
        ListNode *fastLoop = head, *slowLoop = head, * preSlowLoop;
        while(fastLoop != nullptr){
            fastLoop = fastLoop->next;
            if(fastLoop == nullptr){
                break;
            }
            fastLoop = fastLoop->next;
            preSlowLoop = slowLoop;
            slowLoop = slowLoop->next;
        }
        TreeNode * ret = new TreeNode(slowLoop->val);
        preSlowLoop->next = nullptr;
        ret->left = sortedListToBST(head);
        ret->right = sortedListToBST(slowLoop->next);
        return ret;
    }
};
// @lc code=end

