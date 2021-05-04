/*
 * @lc app=leetcode id=144 lang=golang
 *
 * [144] Binary Tree Preorder Traversal
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
func preorderTraversal(root *TreeNode) []int {
	var ret []int
	if root != nil {
		ret = append(ret, root.Val)
		ret = append(ret, preorderTraversal(root.Left)...)
		ret = append(ret, preorderTraversal(root.Right)...)
	}
	return ret
}

// @lc code=end

