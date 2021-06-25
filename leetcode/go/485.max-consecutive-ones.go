/*
 * @lc app=leetcode id=485 lang=golang
 *
 * [485] Max Consecutive Ones
 */

// @lc code=start
func findMaxConsecutiveOnes(nums []int) int {
	ret := 0
	length := len(nums)
	number := 0
	for i := 0; i < length; i++ {
		if nums[i] == 1 {
			number++
		} else {
			if number > ret {
				ret = number
			}
			number = 0
		}
	}
	if number > ret {
		ret = number
	}
	return ret
}

// @lc code=end

