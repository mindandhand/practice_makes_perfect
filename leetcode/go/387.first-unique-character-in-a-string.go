/*
 * @lc app=leetcode id=387 lang=golang
 *
 * [387] First Unique Character in a String
 */

// @lc code=start
func firstUniqChar(s string) int {
	m_map := make([]int, 26)
	len1 := len(s)
	for i := 0; i < len1; i++ {
		m_map[s[i]-'a']++
	}
	for j := 0; j < len1; j++ {
		if m_map[s[j]-'a'] == 1 {
			return j
		}
	}
	return -1
}

// @lc code=end

