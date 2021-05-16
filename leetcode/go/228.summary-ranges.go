/*
 * @lc app=leetcode id=228 lang=golang
 *
 * [228] Summary Ranges
 */
package main

import "fmt"

// @lc code=start
func summaryRanges(nums []int) []string {
	var ret []string
	length := len(nums)
	if length == 0 {
		return ret
	}
	start := 0
	i := 0
	for i = 1; i < length; i++ {
		if nums[i] == nums[i-1]+1 {
			continue
		} else {
			if i-1 == start {
				ret = append(ret, fmt.Sprint(nums[start]))
			} else {
				ret = append(ret, fmt.Sprint(nums[start])+"->"+fmt.Sprint(nums[i-1]))
			}
			start = i
		}
	}
	if i-1 == start {
		ret = append(ret, fmt.Sprint(nums[start]))
	} else {
		ret = append(ret, fmt.Sprint(nums[start])+"->"+fmt.Sprint(nums[i-1]))
	}

	return ret
}
func main() {
	nums := []int{0, 1, 2, 4, 5, 7}
	fmt.Println(summaryRanges(nums))
	nums1 := []int{}
	fmt.Println(summaryRanges(nums1))
	nums2 := []int{-1}
	fmt.Println(summaryRanges(nums2))
}

// @lc code=end
