/*
 * @lc app=leetcode id=482 lang=golang
 *
 * [482] License Key Formatting
 */
package main

import "fmt"

// @lc code=start
func licenseKeyFormatting(s string, k int) string {
	ret := ""
	pos := len(s) - 1
	i := 0
	for pos >= 0 {
		if s[pos] == '-' {

		} else {
			if i == k {
				ret = "-" + ret
				i = 0
			}
			if s[pos] > 94 {
				ret = string(s[pos]-32) + ret
			} else {
				ret = string(s[pos]) + ret
			}
			i++

		}
		pos--
	}
	return ret
}
func main() {
	fmt.Println(licenseKeyFormatting("5F3Z-2e-9-w", 4))
}

// @lc code=end
