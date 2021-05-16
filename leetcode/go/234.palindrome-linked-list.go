/*
 * @lc app=leetcode id=234 lang=golang
 *
 * [234] Palindrome Linked List
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
func isPalindrome(head *ListNode) bool {
	slow := head
	if head.Next == nil {
		return true
	}
	fast := head.Next
	number := 2
	for fast != nil {

		fast = fast.Next
		if fast != nil {
			fast = fast.Next
			number++
			if fast != nil {
				number++
				slow = slow.Next
			}
		}
	}

	if number%2 != 0 {
		slow = slow.Next
	}
	reverse_point := slow.Next
	reverse_point = reverseList(reverse_point)
	loop := reverse_point
	for loop != nil {
		if head.Val != loop.Val {
			break
		}
		head = head.Next
		loop = loop.Next
	}
	reverse_point = reverseList(reverse_point)
	slow.Next = reverse_point
	return loop == nil
}

// @lc code=end

