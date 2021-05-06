/*
 * @lc app=leetcode id=169 lang=golang
 *
 * [169] Majority Element
 */

// @lc code=start
func majorityElement(nums []int) int {
	ret := nums[0]
	length := len(nums)
	number := 1
	for i := 1; i < length; i++ {
		if number == 0 {
			ret = nums[i]
			number++
			continue
		}
		if nums[i] == ret {
			number++
		} else {
			number--
		}
	}
	return ret
}

// @lc code=end

