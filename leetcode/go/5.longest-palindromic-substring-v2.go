// package main

// import "fmt"

/*
 * @lc app=leetcode id=5 lang=golang
 *
 * [5] Longest Palindromic Substring
 */

func longestPalindromeLoop(j int, k int, s string) string {
	var ret string
	for j >= 0 && k < len(s) {
		if s[j] == s[k] {
			if k-j+1 > len(ret) {
				ret = s[j : k+1]
			}
			j--
			k++
			continue
		}
		break
	}
	return ret
}

// @lc code=start
func longestPalindrome(s string) string {
	if len(s) == 0 {
		return ""
	}
	var ret string
	ret = s[0:1]
	var i = 0
	for i < len(s) {
		if i+1 < len(s) && s[i] == s[i+1] {
			retStr := longestPalindromeLoop(i, i+1, s)
			if len(retStr) > len(ret) {
				ret = retStr
			}
		}
		retStr := longestPalindromeLoop(i-1, i+1, s)
		if len(retStr) > len(ret) {
			ret = retStr
		}
		i++
	}
	return ret
}

// func main() {
// 	testStr := "babad"
// 	fmt.Println(testStr, longestPalindrome(testStr))
// 	testStr = "aaa"
// 	fmt.Println(testStr, longestPalindrome(testStr))
// 	testStr = "bab"
// 	fmt.Println(testStr, longestPalindrome(testStr))
// 	testStr = "bb"
// 	fmt.Println(testStr, longestPalindrome(testStr))
// }

// @lc code=end
