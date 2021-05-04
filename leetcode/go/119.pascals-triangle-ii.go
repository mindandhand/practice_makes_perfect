/*
 * @lc app=leetcode id=119 lang=golang
 *
 * [119] Pascal's Triangle II
 */

// @lc code=start
func getRow(rowIndex int) []int {
	ret := make([]int, rowIndex+1)
	for i := 0; i < rowIndex+1; i++ {
		ret[0] = 1
		j := 1
		pre := 1
		for ; j <= i/2; j++ {
			tmp := ret[j]
			ret[j] = pre + tmp
			pre = tmp
		}
		for ; j < i+1; j++ {
			ret[j] = ret[i-j]
		}
	}
	return ret
}

// @lc code=end

