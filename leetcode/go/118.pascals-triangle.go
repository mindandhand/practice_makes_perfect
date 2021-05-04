/*
 * @lc app=leetcode id=118 lang=golang
 *
 * [118] Pascal's Triangle
 */

// @lc code=start
func generate(numRows int) [][]int {
	var ret [][]int
	for i := 0; i < numRows; i++ {
		var level []int
		level = append(level, 1)
		if i >= 2 {
			last_level := ret[i-1]
			for j := 0; j < len(last_level)-1; j++ {
				level = append(level, last_level[j]+last_level[j+1])
			}

		}
		if i != 0 {
			level = append(level, 1)
		}
		ret = append(ret, level)
	}
	return ret
}

// @lc code=end

