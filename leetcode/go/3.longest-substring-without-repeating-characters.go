/*
 * @lc app=leetcode id=3 lang=golang
 *
 * [3] Longest Substring Without Repeating Characters
 */

// @lc code=start
func lengthOfLongestSubstring(s string) int {
	if len(s) == 0 {
		return 0
	}
	var find = false
	pos := 0
	loop := 1
	length := 1
	max_length := 1
	for loop < len(s) {
		i := 0
		find = false
		for i < length {
			if s[pos+i] == s[loop] {
				find = true
				length = loop - pos - i
				pos = pos + i + 1
				loop++
				break
			}
			i++
		}
		if find {
			continue
		}
		length++
		loop++
		if length > max_length {
			max_length = length
		}
	}
	return max_length
}

// @lc code=end
