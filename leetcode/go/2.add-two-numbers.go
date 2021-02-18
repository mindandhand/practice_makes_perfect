/*
 * @lc app=leetcode id=2 lang=golang
 *
 * [2] Add Two Numbers
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func addTwoNumbers(l1 *ListNode, l2 *ListNode) *ListNode {
	if l1 == nil {
		return l2
	}
	if l2 == nil {
		return l1
	}
	var ret, tailNode *ListNode
	ret = nil
	l1Node := l1
	l2Node := l2
	addOne := 0
	firstVal := 0
	secondVal := 0
	for l1Node != nil || l2Node != nil {
		if l1Node != nil {
			firstVal = l1Node.Val
		} else {
			firstVal = 0
		}

		if l2Node != nil {
			secondVal = l2Node.Val
		} else {
			secondVal = 0
		}
		tmp := firstVal + secondVal + addOne
		if tmp > 9 {
			addOne = 1
		} else {
			addOne = 0
		}
		tmp = tmp % 10
		if ret == nil {
			ret = &ListNode{
				Val: tmp,
			}
			tailNode = ret
		} else {
			tailNode.Next = &ListNode{
				Val: tmp,
			}
			tailNode = tailNode.Next
		}
		if l1Node != nil {
			l1Node = l1Node.Next
		}
		if l2Node != nil {
			l2Node = l2Node.Next
		}

	}
	if addOne == 1 {
		tailNode.Next = &ListNode{
			Val: 1,
		}
	}
	return ret
}

// @lc code=end
