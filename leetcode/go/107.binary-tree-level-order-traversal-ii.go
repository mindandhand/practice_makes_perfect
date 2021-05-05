/*
 * @lc app=leetcode id=107 lang=golang
 *
 * [107] Binary Tree Level Order Traversal II
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
func levelOrderBottom(root *TreeNode) [][]int {
	var ret [][]int
	cur_level := 0
	parent_nodes := list.New()
	child_nodes := list.New()
	if root == nil {
		return ret
	}
	parent_nodes.PushBack(root)
	for parent_nodes.Len() > 0 {
		cur_level++
		var level_data []int
		loop_node := parent_nodes.Front()
		for loop_node != nil {
			node := loop_node.Value.(*TreeNode)
			level_data = append(level_data, node.Val)
			if node.Left != nil {
				child_nodes.PushBack(node.Left)
			}
			if node.Right != nil {
				child_nodes.PushBack(node.Right)
			}
			loop_node = loop_node.Next()
		}
		ret = append([][]int{level_data}, ret...)
		parent_nodes.Init()
		parent_nodes.PushBackList(child_nodes)
		child_nodes.Init()
	}
	return ret
}

// @lc code=end

