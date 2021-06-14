/*
 * @lc app=leetcode id=441 lang=golang
 *
 * [441] Arranging Coins
 */

// @lc code=start
func arrangeCoins(n int) int {
	return int(-0.5 + math.Sqrt(float64(2*n)+0.25))
}

// @lc code=end

