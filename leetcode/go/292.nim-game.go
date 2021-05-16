/*
 * @lc app=leetcode id=292 lang=golang
 *
 * [292] Nim Game
 */

// @lc code=start
func canWinNim(n int) bool {
	if n < 1 {
		return false
	}
	if n%4 != 0 {
		return true
	}
	return false

}

// @lc code=end

