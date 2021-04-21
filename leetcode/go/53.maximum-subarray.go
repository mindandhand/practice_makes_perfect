/*
 * @lc app=leetcode id=53 lang=golang
 *
 * [53] Maximum Subarray
 */

package main

import (
	"fmt"
)

// @lc code=start
func maxSubArray(nums []int) int {
	ret := -2147483648
	sum := 0
	for i := 0; i < len(nums); i++ {
		if sum < 0 {
			sum = nums[i]
		} else {
			sum = sum + nums[i]
		}
		if sum > ret {
			ret = sum
		}
	}
	return ret
}
func main() {
	var nums1 = []int{-2, 1, -3, 4, -1, 2, 1, -5, 4}
	fmt.Println(maxSubArray(nums1))
	var nums2 = []int{5, 4, -1, 7, 8}
	fmt.Println(maxSubArray(nums2))
	var nums3 = []int{-2, 1}
	fmt.Println(maxSubArray(nums3))
	var nums4 = []int{-2, -1}
	fmt.Println(maxSubArray(nums4))
}

// @lc code=end
