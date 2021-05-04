/*
 * @lc app=leetcode id=125 lang=golang
 *
 * [125] Valid Palindrome
 */
package main

import (
	"fmt"
	"unicode"
)

// @lc code=start
func isPalindrome(s string) bool {
	rs := []rune(s)
	start := 0
	length := len(s)
	end := length - 1

	for start < end {
		if !(unicode.IsLetter(rs[start]) || unicode.IsNumber(rs[start])) {
			start++
		} else if !(unicode.IsLetter(rs[end]) || unicode.IsNumber(rs[end])) {
			end--
		} else {
			if unicode.ToLower(rs[start]) == unicode.ToLower(rs[end]) {
				start++
				end--
			} else {
				return false
			}
		}
	}
	return true
}

func main() {
	fmt.Println(isPalindrome("A man, a plan, a canal: Panama"))
	fmt.Println(isPalindrome("race a car"))
	fmt.Println(isPalindrome(".,"))
	fmt.Println(isPalindrome("0P"))
}

// @lc code=end
