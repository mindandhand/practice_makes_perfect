/*
 * @lc app=leetcode id=202 lang=golang
 *
 * [202] Happy Number
 */
package main

import "fmt"

// @lc code=start
func isHappy(n int) bool {
	cache := make(map[int]int)
	cache[n] = 1
	tmp := n
	for {
		sum := 0
		for tmp > 0 {
			last := tmp % 10
			sum = sum + last*last
			tmp = tmp / 10
		}
		if sum == 1 {
			return true
		}
		if _, ok := cache[sum]; ok {
			return false
		} else {
			cache[sum] = 1
		}
		tmp = sum

	}
}

func main() {
	fmt.Println(isHappy(19))
	fmt.Println(isHappy(7))
	fmt.Println(isHappy(2))
}

// @lc code=end
