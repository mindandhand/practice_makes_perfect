/*
 * @lc app=leetcode id=476 lang=golang
 *
 * [476] Number Complement
 */

// @lc code=start
func findComplement(num int) int {
	tmp := num
	tmp1 := 0
	len1 := 0
	for tmp > 0 {
		len1++
		tmp = tmp >> 1
		tmp1 = (tmp1 << 1) + 1
	}
	return (num ^ tmp1)
}

// @lc code=end

