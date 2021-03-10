/*
 * @lc app=leetcode id=10 lang=golang
 *
 * [10] Regular Expression Matching
 */
package main

import "fmt"

// @lc code=start
func isMatch(s string, p string) bool {
	len1 := len(s)
	len2 := len(p)
	i := 0
	j := 0
	for i < len1 && j < len2 {
		if s[i] == p[j] || s[j] == '.' {
			j++
		} else if s[j] == '*' {
			if j > 1 && s[j-1] == '.' {
				return true
			} else if j > 1 && s[i] == s[j-1] {

			} else if j > 1 && s[i] != s[j-1] {
				j++
			} else {
				return false
			}
		}
		i++
	}
	if i < len1 {
		return false
	}
	return true
}

func main() {
	fmt.Println(isMatch("aa", "a"))
	fmt.Println(isMatch("aa", "a*"))
	fmt.Println(isMatch("ab", ".*"))
	fmt.Println(isMatch("aab", "c*a*b"))
	fmt.Println(isMatch("mississippi", "mis*is*p*."))
}

// @lc code=end
