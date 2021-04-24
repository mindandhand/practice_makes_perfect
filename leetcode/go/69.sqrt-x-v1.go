/*
 * @lc app=leetcode id=69 lang=golang
 *
 * [69] Sqrt(x)
 */

// @lc code=start
func mySqrt(x int) int {
	ret := 0
	tmp := ret * ret
	for tmp < x {
		ret++
		tmp = ret * ret
	}
	if tmp > x {
		return ret - 1
	}
	return ret
}

// @lc code=end

