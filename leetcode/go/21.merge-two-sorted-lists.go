/*
 * @lc app=leetcode id=21 lang=golang
 *
 * [21] Merge Two Sorted Lists
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
 func mergeTwoLists(l1 *ListNode, l2 *ListNode) *ListNode {
	var head *ListNode
	head = nil
    tail := head  
	last := head
	for l1!= nil && l2 != nil {
		if l1.Val < l2.Val {
			last = l1	
			l1 = l1.Next
		} else {
			last = l2
			l2 = l2.Next
		}
		if head == nil {
			head = last
            tail = head
        } else {
            tail.Next = last
            tail = tail.Next
        }
	}
	if l1 != nil {
        if head == nil {
            return l1
        } 
        tail.Next = l1
        
	}
	if l2 != nil {
        if head == nil {
            return l2
        }
		tail.Next = l2
	}
	return head
}

// @lc code=end

