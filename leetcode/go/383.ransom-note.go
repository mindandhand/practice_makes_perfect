/*
 * @lc app=leetcode id=383 lang=golang
 *
 * [383] Ransom Note
 */
package main

// @lc code=start
func canConstruct(ransomNote string, magazine string) bool {
	m_map := make([]int , 26)
	len1 := len(magazine)
	for i := 0; i < len1; i++ {
		m_map[magazine[i]-'a']++
	}
	len2 := len(ransomNote)
	for i := 0; i < len2; i++ {
		m_map[ransomNote[i]-'a']--
        if m_map[ransomNote[i]-'a'] < 0 {
            return false
        }
	}
	return true
}

// @lc code=end
