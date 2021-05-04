/*
 * @lc app=leetcode id=125 lang=golang
 *
 * [125] Valid Palindrome
 */
package main

import (
	"fmt"
	"strings"
)

// @lc code=start
func isPalindrome(s string) bool {
	s = strings.ToLower(s)
	start := 0
	length := len(s)
	end := length - 1

	for start < end {
		for start < length && !((s[start] >= 'a' && s[start] <= 'z') || (s[start] >= '0' && s[start] <= '9')) {
			start++
		}
		for end >= 0 && !((s[end] >= 'a' && s[end] <= 'z') || (s[end] >= '0' && s[end] <= '9')) {
			end--
		}
		if start >= length || end < 0 {
			break
		}
		if s[start] == s[end] {
			start++
			end--
		} else {
			return false
		}
	}
	return true
}

func main() {
	// fmt.Println(isPalindrome("A man, a plan, a canal: Panama"))
	// fmt.Println(isPalindrome("race a car"))
	fmt.Println(isPalindrome(".,"))
	fmt.Println(isPalindrome("0P"))
}

// @lc code=end
