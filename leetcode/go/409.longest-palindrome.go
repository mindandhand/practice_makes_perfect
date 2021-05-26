/*
 * @lc app=leetcode id=409 lang=golang
 *
 * [409] Longest Palindrome
 */

// @lc code=start
func longestPalindrome(s string) int {
	var stat [52]int
	length := len(s)
	for i := 0; i < length; i++ {
		if s[i] >= 97 {
			// lower
			stat[s[i]-'A'-6]++
		} else {
			stat[s[i]-'A']++
		}
	}
	ret := 0
	for i := 0; i < 52; i++ {
		if stat[i]%2 == 0 {
			ret = ret + stat[i]
		} else {
			ret = ret + stat[i] - 1
		}
	}
	if ret < length {
		ret++
	}
	return ret
}

// @lc code=end

