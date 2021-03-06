/*
 * @lc app=leetcode id=5 lang=golang
 *
 * [5] Longest Palindromic Substring
 */
// package main

// import "fmt"

// @lc code=start
func longestPalindrome(s string) string {
	if len(s) == 0 || len(s) == 1 {
		return s
	}
	ret := string(s[0])
	i := 0
	for i < len(s)-1 {
		j := len(s) - 1
		for j > i {
			// fmt.Println(i, j)
			if s[j] == s[i] {
				// may palindrome there
				h := i + 1
				k := j - 1
				for h < k {
					if s[h] != s[k] {
						break
					}
					h++
					k--
				}
				if h >= k && j-i+1 > len(ret) {
					ret = s[i : j+1]
				}
			}
			j--
		}
		i++
	}
	return ret
}

// func main() {
// 	fmt.Println(longestPalindrome("ac"))
// 	fmt.Println(longestPalindrome("abb"))
// 	fmt.Println(longestPalindrome("aacabdkacaa"))
// 	fmt.Println(longestPalindrome("bab"))
// 	fmt.Println(longestPalindrome("bbvbb"))
// }

// @lc code=end
