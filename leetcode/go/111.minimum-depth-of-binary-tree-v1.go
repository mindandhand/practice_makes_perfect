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

import "fmt"

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func minDepth(root *TreeNode) int {
	if root == nil {
		return 0
	}
	if root.Left == nil && root.Right == nil {
		return 1
	}

	left := minDepth(root.Left)
	right := minDepth(root.Right)
	fmt.Println("left:", left)
	if left == 0 {
		return 1 + right
	} else if right == 0 {
		fmt.Println("1 + left:", 1+left)
		return 1 + left
	} else if left <= right {
		return 1 + left
	}
	return 1 + right
}

func main() {
	root := &TreeNode{
		Val: 2,
	}
	left := &TreeNode{
		Val: 1,
	}
	root.Left = left
	root.Right = nil
	fmt.Println(minDepth(root))
}

// @lc code=end
