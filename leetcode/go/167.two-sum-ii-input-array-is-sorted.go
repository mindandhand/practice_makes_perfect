/*
 * @lc app=leetcode id=167 lang=golang
 *
 * [167] Two Sum II - Input array is sorted
 */

// @lc code=start
func twoSum(numbers []int, target int) []int {
	var ret []int
	start := 0
	end := len(numbers) - 1
	for {
		sum := numbers[start] + numbers[end]
		if sum == target {
			ret = append(ret, start)
			ret = append(ret, end)
			break
		} else if sum < target {
			start++
		} else {
			end--
		}
	}
	return ret
}

// @lc code=end

