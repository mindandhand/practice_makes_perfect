/*
 * @lc app=leetcode id=160 lang=golang
 *
 * [160] Intersection of Two Linked Lists
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func getIntersectionNode(headA, headB *ListNode) *ListNode {
	lengthA := 0
	lengthB := 0
	for tmpA := headA; tmpA != nil; tmpA = tmpA.Next {
		lengthA++
	}
	for tmpB := headB; tmpB != nil; tmpB = tmpB.Next {
		lengthB++
	}
	tmpA := headA
	tmpB := headB
	for lengthA > lengthB {
		lengthA--
		tmpA = tmpA.Next
	}
	for lengthB > lengthA {
		lengthB--
		tmpB = tmpB.Next
	}
	ret := tmpA
	for tmpA != nil {
		if tmpA != tmpB {
			ret = tmpA.Next
		}
		tmpA = tmpA.Next
		tmpB = tmpB.Next
	}
	return ret
}

// @lc code=end

