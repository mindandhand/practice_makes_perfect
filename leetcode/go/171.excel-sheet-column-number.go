/*
 * @lc app=leetcode id=171 lang=golang
 *
 * [171] Excel Sheet Column Number
 */

// @lc code=start
package main

import "fmt"

func titleToNumber(columnTitle string) int {
	ret := 0
	length := len(columnTitle)
	for i := 0; i < length; i++ {
		ret = int(columnTitle[i]-'A') + 1 + ret*26
	}
	return ret
}

func main() {
	fmt.Println(titleToNumber("A"))
	fmt.Println(titleToNumber("Z"))
	fmt.Println(titleToNumber("AB"))
	fmt.Println(titleToNumber("ZY"))
}

// @lc code=end
