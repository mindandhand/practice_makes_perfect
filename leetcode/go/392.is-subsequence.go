/*
 * @lc app=leetcode id=392 lang=golang
 *
 * [392] Is Subsequence
 */

// @lc code=start
func isSubsequence(s string, t string) bool {
	len1 := len(s)
	len2 := len(t)
	j := 0
	for i := 0; i < len2 && j < len1; i++ {
		if s[j] == t[i] {
			j++
		}
	}
	if j == len1 {
		return true
	}
	return false
}

// @lc code=end

