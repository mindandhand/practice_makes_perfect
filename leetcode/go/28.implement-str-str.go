/*
 * @lc app=leetcode id=28 lang=golang
 *
 * [28] Implement strStr()
 */
package main

import "fmt"

// @lc code=start
func strStr(haystack string, needle string) int {
	length := len(haystack)
	sub_length := len(needle)
	if sub_length == 0 {
		return 0
	}
	for i := 0; i <= length-sub_length; {
		sub_i := 0
		for sub_i < sub_length && (haystack[i+sub_i]) == (needle[sub_i]) {
			sub_i++
		}
		if sub_i == sub_length {
			return i
		}
		i++
	}
	return -1
}

func main() {
	// fmt.Println(strStr("hello", "ll"))
	fmt.Println(strStr("mississippi", "issip"))
}

// @lc code=end
