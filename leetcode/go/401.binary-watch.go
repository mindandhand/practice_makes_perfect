/*
 * @lc app=leetcode id=401 lang=golang
 *
 * [401] Binary Watch
 */

// @lc code=start
package main

import "fmt"

func hammingWeight(num int) int {
	ret := 0
	for num > 0 {
		num = num & (num - 1)
		ret++
	}
	return ret
}

func readBinaryWatch(turnedOn int) []string {
	var ret []string
	for i := 0; i < 12; i++ {
		for j := 0; j < 60; j++ {
			if hammingWeight(i<<6+j) == turnedOn {
				time_str := fmt.Sprintf("%d:%02d", i, j)
				ret = append(ret, time_str)
			}
		}
	}
	return ret
}

func main() {
	fmt.Println(readBinaryWatch(1))
}

// @lc code=end
