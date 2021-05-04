/*
 * @lc app=leetcode id=145 lang=golang
 *
 * [145] Binary Tree Postorder Traversal
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
func postorderTraversal(root *TreeNode) []int {
	var ret []int
	if root != nil {
		ret = append(ret, postorderTraversal(root.Left)...)
		ret = append(ret, postorderTraversal(root.Right)...)
		ret = append(ret, root.Val)
	}
	return ret
}

// @lc code=end

