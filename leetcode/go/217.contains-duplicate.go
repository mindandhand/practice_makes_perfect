/*
 * @lc app=leetcode id=217 lang=golang
 *
 * [217] Contains Duplicate
 */

// @lc code=start
func containsDuplicate(nums []int) bool {
	contains := make(map[int]int)
	for i := 0; i < len(nums); i++ {
		if _, ok := contains[nums[i]]; ok {
			return true
		} else {
			contains[nums[i]] = 1
		}
	}
	return false
}

// @lc code=end

