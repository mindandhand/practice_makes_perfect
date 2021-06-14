/*
 * @lc app=leetcode id=448 lang=golang
 *
 * [448] Find All Numbers Disappeared in an Array
 */

// @lc code=start
func findDisappearedNumbers(nums []int) []int {
	length := len(nums)
	for i := 0; i < length; i++ {
		if nums[i] == 0 {
			continue
		}
		val := nums[i]
		for nums[val-1] != 0 {
			tmp := nums[val-1]
			nums[val-1] = 0
			val = tmp
		}

	}
	var ret []int
	for i := 0; i < length; i++ {
		if nums[i] != 0 {
			ret = append(ret, i+1)
		}
	}
	return ret
}

// @lc code=end

