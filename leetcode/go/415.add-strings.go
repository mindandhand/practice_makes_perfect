/*
 * @lc app=leetcode id=415 lang=golang
 *
 * [415] Add Strings
 */

package main

import "fmt"

// @lc code=start
func addStrings(num1 string, num2 string) string {
	var ret string
	plus_one := false
	len1 := len(num1) - 1
	len2 := len(num2) - 1
	var tmp_sum byte
	var tmp1 byte
	var tmp2 byte
	for len1 >= 0 || len2 >= 0 {
		if len1 >= 0 {
			tmp1 = num1[len1]
		} else {
			tmp1 = '0'
		}
		if len2 >= 0 {
			tmp2 = num2[len2]
		} else {
			tmp2 = '0'
		}
		tmp_sum = tmp1 + tmp2 - '0'
		if plus_one {
			tmp_sum = tmp_sum + 1
		}
		if tmp_sum-'0' > 9 {
			plus_one = true
			ret = string(tmp_sum-10) + ret
		} else {
			plus_one = false
			ret = string(tmp_sum) + ret
		}

		len1--
		len2--
	}
	if plus_one {
		ret = "1" + ret
	}
	return ret
}

func main() {
	fmt.Println(addStrings("0", "0"))
	fmt.Println(addStrings("456", "77"))
}

// @lc code=end
