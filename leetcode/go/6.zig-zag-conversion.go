/*
 * @lc app=leetcode id=6 lang=golang
 *
 * [6] ZigZag Conversion
 */

// @lc code=start
func convert(s string, numRows int) string {
	if numRows == 1 {
		return s
	}
	rowDatas := make([]string, numRows)

	i := 0
	downDir := true
	for i < len(s) {
		if downDir {
			lineNumber := i % (numRows*2 - 2)
			rowDatas[lineNumber] = rowDatas[lineNumber] + string(s[i])
			if lineNumber+1 == numRows && numRows > 2 {
				downDir = false
			}
		} else {
			lineNumber := numRows*2 - 2 - i%(numRows*2-2)
			rowDatas[lineNumber] = rowDatas[lineNumber] + string(s[i])
			if lineNumber == 1 {
				downDir = true
			}
		}
		i++
	}
	i = 0
	var ret string
	for i < numRows {
		ret += rowDatas[i]
		i++
	}
	return ret
}

// @lc code=end

