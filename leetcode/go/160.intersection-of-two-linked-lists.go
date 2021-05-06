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
	cache := make(map[*ListNode]int)
	for tmp := headA; tmp != nil; tmp = tmp.Next {
		cache[tmp] = 0
	}
	for tmp := headB; tmp != nil; tmp = tmp.Next {
		if _, ok := cache[tmp]; ok {
			return tmp
		}
	}
	return nil
}

// @lc code=end

