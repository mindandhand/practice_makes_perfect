/*
 * @lc app=leetcode id=344 lang=golang
 *
 * [344] Reverse String
 */

// @lc code=start
func reverseString(s []byte) {
	start := 0
	end := len(s) - 1
	for start < end {
		tmp := s[start]
		s[start] = s[end]
		s[end] = tmp
		start++
		end--
	}
}

// @lc code=end

