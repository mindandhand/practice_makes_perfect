/*
 * @lc app=leetcode id=101 lang=golang
 *
 * [101] Symmetric Tree
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
func isValEqual(left *TreeNode, right *TreeNode) bool {
	if left == nil && right == nil {
		return true
	}
	if left == nil || right == nil {
		return false
	}
	if left.Val == right.Val {
		return isValEqual(left.Left, right.Right) && isValEqual(left.Right, right.Left)
	}
	return false
}
func isSymmetric(root *TreeNode) bool {
	if root == nil {
		return true
	}
	return isValEqual(root.Left, root.Right)
}

// @lc code=end

