/*
 * @lc app=leetcode id=257 lang=golang
 *
 * [257] Binary Tree Paths
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
func addNode(node *TreeNode, parentNode []*TreeNode) []string {
	var ret []string
	if node == nil {
		return ret
	} else if node.Left == nil && node.Right == nil {
		// last node
		addStr := ""
		for i := 0; i < len(parentNode); i++ {
			if addStr == "" {
				addStr = fmt.Sprint(parentNode[i].Val)
			} else {
				addStr = addStr + "->" + fmt.Sprint(parentNode[i].Val)
			}
		}
		if addStr == "" {
			addStr = fmt.Sprint(node.Val)
		} else {
			addStr = addStr + "->" + fmt.Sprint(node.Val)
		}
		ret = append(ret, addStr)
	} else {
		parentNode = append(parentNode, node)
		return append(append(ret, addNode(node.Left, parentNode)...), addNode(node.Right, parentNode)...)
	}
	return ret
}
func binaryTreePaths(root *TreeNode) []string {
	var ret []string
	if root == nil {
		return ret
	} else {
		var parentNode []*TreeNode
		return addNode(root, parentNode)
	}
}

// @lc code=end

