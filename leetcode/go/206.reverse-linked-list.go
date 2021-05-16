/*
 * @lc app=leetcode id=206 lang=golang
 *
 * [206] Reverse Linked List
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func reverseList(head *ListNode) *ListNode {
	if head == nil {
		return head
	}
	var ret *ListNode
	ret = nil
	for head != nil {
		tmp := head.Next
		if ret == nil {
			ret = head
			ret.Next = nil
		} else {
			head.Next = ret
			ret = head
		}
		head = tmp
	}
	return ret
}

// @lc code=end

