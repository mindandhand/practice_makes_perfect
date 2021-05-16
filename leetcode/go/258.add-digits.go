/*
 * @lc app=leetcode id=258 lang=golang
 *
 * [258] Add Digits
 */

// @lc code=start
func addDigits(num int) int {
	ret := 0
	for {
		for num > 0 {
			ret = ret + num%10
			num = num / 10
		}
		if ret < 10 {
			return ret
		} else {
			num = ret
			ret = 0
		}
	}
	return ret
}

// @lc code=end

