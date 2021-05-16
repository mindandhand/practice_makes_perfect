/*
 * @lc app=leetcode id=219 lang=golang
 *
 * [219] Contains Duplicate II
 */

// @lc code=start
func containsNearbyDuplicate(nums []int, k int) bool {
	contains := make(map[int]int)
	for i := 0; i < len(nums); i++ {
		if value, ok := contains[nums[i]]; ok && i-value <= k {
			return true
		} else {
			contains[nums[i]] = i
		}
	}
	return false
}

// @lc code=end

