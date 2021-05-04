/*
 * @lc app=leetcode id=110 lang=golang
 *
 * [110] Balanced Binary Tree
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func maxDepth(root *TreeNode) int {
	if root == nil {
		return 0
	}
	left := 1 + maxDepth(root.Left)
	right := 1 + maxDepth(root.Right)
	if left > right {
		return left
	}
	return right
}
func isBalanced(root *TreeNode) bool {
	if root == nil {
		return true
	}

	if maxDepth(root.Left)-maxDepth(root.Right) >= -1 && maxDepth(root.Left)-maxDepth(root.Right) <= 1 {
		return isBalanced(root.Left) && isBalanced(root.Right)
	}
	return false
}

// @lc code=end
