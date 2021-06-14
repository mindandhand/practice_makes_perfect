/*
 * @lc app=leetcode id=434 lang=golang
 *
 * [434] Number of Segments in a String
 */
package main

import (
	"fmt"
)

// @lc code=start
func countSegments(s string) int {
	ret := 0
	length := len(s)
	i := 0
	for ; i < length; i++ {
		if i > 0 && s[i] == ' ' && s[i-1] != ' ' {
			ret++
		} else if s[i] == ' ' && ret == 0 {
			continue
		}
	}

	if i == length && i > 0 && s[i-1] != ' ' {
		ret++
	}
	return ret
}
func main() {
	fmt.Println(countSegments("Hello, my name is John"))
}

// @lc code=end
