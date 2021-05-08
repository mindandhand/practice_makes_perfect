/*
 * @lc app=leetcode id=190 lang=golang
 *
 * [190] Reverse Bits
 */
package main

import (
	"fmt"
)

// @lc code=start
func reverseBits(num uint32) uint32 {
	var ret uint32
	var last uint32
	ret = 0
	total := 31
	for total >= 0 {
		if num > 0 {
			last = 0
			last = num & 1
			ret = (ret) ^ (last << total)
			num = num >> 1

		}
		total--
	}
	return ret
}

func main() {
	fmt.Println(reverseBits(43261596))
}

// @lc code=end
