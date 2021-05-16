/*
 * @lc app=leetcode id=290 lang=golang
 *
 * [290] Word Pattern
 */
package main

import (
	"fmt"
	"strings"
)

// @lc code=start
func wordPattern(pattern string, s string) bool {
	strs := strings.Split(s, " ")
	if len(pattern) != len(strs) {
		return false
	}
	length := len(pattern)
	p_map := make(map[byte]int)
	s_map := make(map[string]int)
	for i := 0; i < length; i++ {
		if p_map[pattern[i]] != s_map[strs[i]] {
			return false
		}
		p_map[pattern[i]] = i + 1
		s_map[strs[i]] = i + 1
	}
	return true
}
func main() {
	fmt.Println(wordPattern("abba", "dog cat cat dog"))
	fmt.Println(wordPattern("abba", "dog cat cat fish"))
	fmt.Println(wordPattern("abaa", "dog cat cat dog"))
}

// @lc code=end
