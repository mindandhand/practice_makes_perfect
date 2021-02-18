package leetcode

/*
 * @lc app=leetcode id=1 lang=golang
 *
 * [1] Two Sum
 */

// @lc code=start
func twoSum(nums []int, target int) []int {
	var ret []int
	length := len(nums)
	loopOn := true
	var i, j int
	for i = 0; i <= length-2; i++ {
		for j = i + 1; j <= length-1; j++ {
			if nums[i]+nums[j] == target {
				loopOn = false
				break
			}
		}
		if !loopOn {
			break
		}
	}
	ret = append(ret, i)
	ret = append(ret, j)
	return ret
}

// @lc code=end
