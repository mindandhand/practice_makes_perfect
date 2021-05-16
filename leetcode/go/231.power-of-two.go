/*
 * @lc app=leetcode id=231 lang=golang
 *
 * [231] Power of Two
 */

// @lc code=start
func isPowerOfTwo(n int) bool {
	i := 1
	for {
		if i == n {
			return true
		} else if i > n {
			return false
		} else {
			i = i * 2
		}
	}
}

// @lc code=end

