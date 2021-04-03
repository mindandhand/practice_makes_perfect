/*
 * @lc app=leetcode id=35 lang=golang
 *
 * [35] Search Insert Position
 */

// @lc code=start
func searchInsert(nums []int, target int) int {
	length := len(nums)
	if length == 0 || target < nums[0] {
		return 0
	}
	if target > nums[length-1] {
		return length
	}
	start := 0
	end := length - 1

	for start < end {
		mid := (start + end) / 2
		if nums[mid] < target {
			if start == mid {
				start++
			} else {
				start = mid
			}
		} else if nums[mid] > target {
			end = mid
		} else {
			return mid
		}
	}
	return start
}

// @lc code=end
