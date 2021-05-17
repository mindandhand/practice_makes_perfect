/*
 * @lc app=leetcode id=342 lang=golang
 *
 * [342] Power of Four
 */

// @lc code=start
func isPowerOfFour(n int) bool {
	i := 1
	for {
		if i == n {
			return true
		} else if i > n {
			return false
		} else {
			i = i * 4
		}
	}
}

// @lc code=end

