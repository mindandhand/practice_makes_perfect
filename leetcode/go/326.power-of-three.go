/*
 * @lc app=leetcode id=326 lang=golang
 *
 * [326] Power of Three
 */

// @lc code=start
func isPowerOfThree(n int) bool {
	i := 1
	for {
		if i == n {
			return true
		} else if i > n {
			return false
		} else {
			i = i * 3
		}
	}
}

// @lc code=end

