/*
 * @lc app=leetcode id=136 lang=golang
 *
 * [136] Single Number
 */

// @lc code=start
func singleNumber(nums []int) int {
	length := len(nums)
	ret := 0
	for i := 0; i < length; i++ {
		ret = ret ^ nums[i]
	}
	return ret
}

// @lc code=end

