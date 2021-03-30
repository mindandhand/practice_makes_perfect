/*
 * @lc app=leetcode id=27 lang=golang
 *
 * [27] Remove Element
 */

// @lc code=start
func removeElement(nums []int, val int) int {
	length := len(nums)
	ret := 0
	for i:= 0;i < length; i++{
		if nums[i] != val {
			nums[ret] = nums[i]
			ret++
		}
	}
    return ret
}
// @lc code=end

