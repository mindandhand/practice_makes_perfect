/*
 * @lc app=leetcode id=283 lang=golang
 *
 * [283] Move Zeroes
 */

func moveZeroes(nums []int) {
	i := 0
	length := len(nums)
	j := 0
	for j < length {
		for i < length && nums[i] != 0 {
			i++
		}
		if j == 0 {
			j = i
		}
		for j < length && nums[j] == 0 {
			j++
		}
		for j < length && nums[i] == 0 && nums[j] != 0 {
			nums[i] = nums[j]
			nums[j] = 0
			i++
			j++
		}
	}

}

// @lc code=end
