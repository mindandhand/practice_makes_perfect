/*
 * @lc app=leetcode id=414 lang=golang
 *
 * [414] Third Maximum Number
 */

package main

import "fmt"

// @lc code=start
func thirdMax(nums []int) int {
	var has_val [3]bool
	for i := 0; i < 3; i++ {
		has_val[i] = false
	}
	var top3 [3]int
	length := len(nums)
	for i := 0; i < length; i++ {
		val := nums[i]
		for j := 0; j < 3; j++ {
			if !has_val[j] {
				has_val[j] = true
				top3[j] = val
				break
			} else if top3[j] < val {
				tmp := val
				val = top3[j]
				top3[j] = tmp
			} else if top3[j] == val {
				break
			}
		}
	}
	if has_val[2] {
		return top3[2]
	} else {
		return top3[0]
	}
}

func main() {
	nums2 := []int{3, 2, 1}
	fmt.Println(thirdMax(nums2))
	nums1 := []int{1, 2}
	fmt.Println(thirdMax(nums1))

	nums3 := []int{2, 2, 3, 1}
	fmt.Println(thirdMax(nums3))
}

// @lc code=end
