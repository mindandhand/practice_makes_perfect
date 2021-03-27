/*
 * @lc app=leetcode id=26 lang=golang
 *
 * [26] Remove Duplicates from Sorted Array
 */

// @lc code=start
func removeDuplicates(nums []int) int {
	length := len(nums)
	if length == 0 {
		return 0
	}
	count := 1
	for i := 0; i+1 < length; i++ {
		if nums[i] == nums[i + 1] {
			continue
		} else {
			nums[count] = nums[i + 1]
			count++
		}
	}
	return count
}

// @lc code=end

