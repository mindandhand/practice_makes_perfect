/*
 * @lc app=leetcode id=111 lang=golang
 *
 * [111] Minimum Depth of Binary Tree
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
package main

import (
	"container/list"
	"fmt"
)

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func minDepth(root *TreeNode) int {
	cur_level := 0
	parent_nodes := list.New()
	child_nodes := list.New()
	if root == nil {
		return 0
	}
	parent_nodes.PushBack(root)
	for {
		// fmt.Println(parent_nodes.Len())
		// fmt.Println(child_nodes.Len())
		cur_level++
		loop_node := parent_nodes.Front()
		for loop_node != nil {
			node := loop_node.Value.(*TreeNode)
			if node.Left == nil && node.Right == nil {
				return cur_level
			}
			if node.Left != nil {
				child_nodes.PushBack(node.Left)
			}
			if node.Right != nil {
				child_nodes.PushBack(node.Right)
			}
			loop_node = loop_node.Next()
		}
		parent_nodes.Init()
		parent_nodes.PushBackList(child_nodes)
		child_nodes.Init()

	}

}

func main() {
	root := &TreeNode{
		Val: 3,
	}
	left := &TreeNode{
		Val: 9,
	}
	root.Left = left
	right := &TreeNode{
		Val: 20,
	}
	root.Right = right
	fmt.Println(minDepth(root))

}

// @lc code=end
