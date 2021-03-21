/*
 * @lc app=leetcode id=14 lang=golang
 *
 * [14] Longest Common Prefix
 */
package main

import "fmt"

// @lc code=start
func longestCommonPrefix(strs []string) string {
	ret := ""
	length := len(strs)
	if length <= 0 {
		return ret
	}
	if length == 1 {
		return strs[0]
	}
	for j := 0; j < len(strs[0]); j++ {
		for i := 1; i < length; i++ {
			if j < len(strs[0]) && j < len(strs[i]) && strs[i][j] == strs[0][j] {
				if i == length-1 {
					ret = strs[0][:j+1]
				}
				continue
			} else {
				return ret
			}
		}
	}
	return ret
}

func main() {
	var strs []string
	fmt.Println(longestCommonPrefix(strs))
	strs = append(strs, "flower")
	strs = append(strs, "flow")
	strs = append(strs, "flight")
	fmt.Println(longestCommonPrefix(strs))
	var strs2 []string
	strs2 = append(strs2, "ab")
	strs2 = append(strs2, "a")
	fmt.Println(longestCommonPrefix(strs2))
}

// @lc code=end
