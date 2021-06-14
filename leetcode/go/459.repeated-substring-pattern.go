/*
 * @lc app=leetcode id=459 lang=golang
 *
 * [459] Repeated Substring Pattern
 */

// @lc code=start
func repeatedSubstringPattern(s string) bool {

	len1 := len(s)
	if len1 <= 1 {
		return false
	}
	half := len(s) / 2
	for i := 1; i <= half; i++ {
		if len1%i != 0 {
			continue
		}
		j := 0
		for j = i; j < len1; j = j + i {
			k := 0
			for k < i && s[k] == s[j+k] {
				k++
			}
			if k < i {
				break
			}
		}
		if j >= len1 {
			return true
		}
	}
	return false
}

// @lc code=end

