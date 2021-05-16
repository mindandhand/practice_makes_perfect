/*
 * @lc app=leetcode id=205 lang=golang
 *
 * [205] Isomorphic Strings
 */

// @lc code=start
func isIsomorphic(s string, t string) bool {

	var s_map = make(map[byte]int)
	var t_map = make(map[byte]int)
	length := len(s)
	count := 0
	for i := 0; i < length; i++ {
		s_map[s[i]]++
		t_map[t[i]]++
		if s_map[s[i]] != t_map[t[i]] {
			return false
		}
	}
	return true
}

// @lc code=end

