/*
 * @lc app=leetcode id=108 lang=golang
 *
 * [108] Convert Sorted Array to Binary Search Tree
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

func printTreeNode(node *TreeNode) {
	if node == nil {
		return
	}
	printTreeNode(node.Left)
	fmt.Println(node.Val)
	printTreeNode(node.Right)
}

func sortedArrayToBST(nums []int) *TreeNode {
	length := len(nums)
	if length == 1 {
		ret := &TreeNode{
			Val: nums[0],
		}
		return ret
	}

	mid := length / 2
	// fmt.Println("nums:%v, insert:%d", nums, nums[mid])
	ret := &TreeNode{
		Val: nums[mid],
	}
	if mid > 0 {
		ret.Left = sortedArrayToBST(nums[0:mid])
	}
	if mid < length-1 {
		ret.Right = sortedArrayToBST(nums[mid+1:])
	}
	return ret
}
func main() {
	nums := []int{-10, -3, 0, 5, 9}
	printTreeNode(sortedArrayToBST(nums))
}

// @lc code=end
