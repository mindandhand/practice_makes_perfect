/*
 * @lc app=leetcode id=141 lang=golang
 *
 * [141] Linked List Cycle
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func hasCycle(head *ListNode) bool {
	if head == nil {
		return false
	}
	first := head
	second := head.Next
	for first != second && second != nil {
		first = first.Next
		second = second.Next
		if second == nil {
			break
		} else {
			second = second.Next
		}
	}
	if second == nil {
		return false
	}
	return true
}

// @lc code=end

