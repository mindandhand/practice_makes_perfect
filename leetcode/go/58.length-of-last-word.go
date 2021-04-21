/*
 * @lc app=leetcode id=58 lang=golang
 *
 * [58] Length of Last Word
 */

// @lc code=start
func lengthOfLastWord(s string) int {
	pos := len(s) - 1
	ret := 0
	for pos >= 0 && s[pos] == ' ' {
		pos--
	}
	for pos >= 0 && s[pos] != ' ' {
		pos--
		ret++
	}
	return ret

}

// @lc code=end

