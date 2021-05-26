/*
 * @lc app=leetcode id=405 lang=golang
 *
 * [405] Convert a Number to Hexadecimal
 */

package main

import (
	"fmt"
	"math"
)

// @lc code=start
func toHex(num int) string {
	if num == 0 {
		return "0"
	}
	ret := ""
	var deal_num uint32
	if num >= 0 {
		deal_num = uint32(num)
	} else {
		deal_num = uint32(-num) ^ math.MaxUint32 + 1

	}
	for deal_num > 0 {
		left := deal_num % 16
		deal_num = deal_num / 16
		switch left {
		case 10:
			ret = "a" + ret
		case 11:
			ret = "b" + ret
		case 12:
			ret = "c" + ret
		case 13:
			ret = "d" + ret
		case 14:
			ret = "e" + ret
		case 15:
			ret = "f" + ret
		default:
			ret = fmt.Sprint(left) + ret
		}
	}
	return ret
}
func main() {
	fmt.Println(toHex(26))
	fmt.Println(toHex(-1))
}

// @lc code=end
