/*
 * @lc app=leetcode id=203 lang=golang
 *
 * [203] Remove Linked List Elements
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func removeElements(head *ListNode, val int) *ListNode {
	for head != nil && head.Val == val {
		head = head.Next
	}
	loop := head
	if loop == nil {
		return nil
	}
	for loop.Next != nil {
		if loop.Next.Val == val {
			loop.Next = loop.Next.Next
		} else {
			loop = loop.Next
		}
	}
	return head
}

// @lc code=end

