/*
 * @lc app=leetcode id=461 lang=golang
 *
 * [461] Hamming Distance
 */

// @lc code=start
func hammingDistance(x int, y int) int {
	ret := 0
	z := x ^ y
	for z > 0 {
		ret++
		z = z & (z - 1)
	}
	return ret
}

// @lc code=end

