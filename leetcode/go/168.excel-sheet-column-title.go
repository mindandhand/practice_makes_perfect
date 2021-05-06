/*
 * @lc app=leetcode id=168 lang=golang
 *
 * [168] Excel Sheet Column Title
 */

// @lc code=start
package main

import (
	"fmt"
)

func convertToTitle(columnNumber int) string {
	ret := ""
	for columnNumber > 0 {

		digit := (columnNumber) % 26
		if digit == 0 {
			ret = "Z" + ret
			columnNumber--
		} else {
			ret = string(byte('A'+digit-1)) + ret
		}
		columnNumber = columnNumber / 26
	}
	return ret
}
func main() {
	fmt.Println(convertToTitle(1))
	fmt.Println(convertToTitle(26))
	fmt.Println(convertToTitle(28))
	// fmt.Println(convertToTitle(52))
	fmt.Println(convertToTitle(701))
	fmt.Println(convertToTitle(2147483647))
}

// @lc code=end
