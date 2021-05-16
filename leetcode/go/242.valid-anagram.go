/*
 * @lc app=leetcode id=242 lang=golang
 *
 * [242] Valid Anagram
 */

// @lc code=start
func isAnagram(s string, t string) bool {
	if len(s) != len(t) {
		return false
	}
	length := len(s)
	byte_map := make(map[byte]int)
	for i := 0; i < length; i++ {
		byte_map[s[i]]++
	}
	for i := 0; i < length; i++ {
		if number, ok := byte_map[t[i]]; ok {
			if number == 1 {
				delete(byte_map, t[i])
			} else {
				byte_map[t[i]]--
			}
		} else {
			return false
		}
	}
	return len(byte_map) == 0
}

// @lc code=end
