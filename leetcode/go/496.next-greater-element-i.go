/*
 * @lc app=leetcode id=496 lang=golang
 *
 * [496] Next Greater Element I
 */

package main

import "container/list"

// @lc code=start
func nextGreaterElement(nums1 []int, nums2 []int) []int {
	var ret []int
	num_stack := list.New()
	next_bigger_map := make(map[int]int)
	for i := 0; i < len(nums2); i++ {
		for num_stack.Len() > 0 && num_stack.Front().Value.(int) < nums2[i] {
			element := num_stack.Front()
			next_bigger_map[element.Value.(int)] = nums2[i]
			num_stack.Remove(element)
		}
		num_stack.PushFront(nums2[i])
	}
	for i := 0; i < len(nums1); i++ {
		if val, ok := next_bigger_map[nums1[i]]; ok {
			ret = append(ret, val)
		} else {
			ret = append(ret, -1)
		}
	}
	return ret
}

// @lc code=end
