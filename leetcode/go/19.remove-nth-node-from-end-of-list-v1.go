/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func removeNthFromEnd(head *ListNode, n int) *ListNode {
	if head == nil {
		return nil
	}
	ret := head
	num := 1
	for ret.Next != nil {
		num++
		ret = ret.Next
	}
	delNum := num - n
	if delNum == 0 {
		head = head.Next
		return head
	}
	ret = head
	for delNum > 1 {
		ret = ret.Next
		delNum--
	}
	ret.Next = ret.Next.Next
	return head
}

// @lc code=end