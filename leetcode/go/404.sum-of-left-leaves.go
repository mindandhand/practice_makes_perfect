/*
 * @lc app=leetcode id=404 lang=golang
 *
 * [404] Sum of Left Leaves
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
func sumOfLeftLeaves(root *TreeNode) int {
	ret := 0
	if root == nil || (root.Left == nil && root.Right == nil) {
		return ret
	}
	if root.Left != nil && root.Left.Left == nil && root.Left.Right == nil {
		ret = ret + root.Left.Val
	}
	return ret + sumOfLeftLeaves(root.Left) + sumOfLeftLeaves(root.Right)
}

// @lc code=end

