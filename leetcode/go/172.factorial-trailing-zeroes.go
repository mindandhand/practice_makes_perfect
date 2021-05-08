/*
 * @lc app=leetcode id=172 lang=golang
 *
 * [172] Factorial Trailing Zeroes
 */

// @lc code=start
func trailingZeroes(n int) int {
	ret := 0
	for i := 0; i <= n; i = i + 5 {
		tmp := i
		for tmp%5 == 0 && tmp > 4 {
			ret++
			tmp = tmp / 5
		}
	}
	return ret
}

// @lc code=end

