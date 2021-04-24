/*
 * @lc app=leetcode id=70 lang=golang
 *
 * [70] Climbing Stairs
 */
package main

import "fmt"

// @lc code=start
func climbStairs(n int) int {
	ret := 0
	if n == 1 {
		return 1
	}
	if n == 2 {
		return 2
	}
	pre_last := 1
	last := 2

	for i := 3; i <= n; i++ {
		ret = last + pre_last
		pre_last = last
		last = ret
	}
	return ret
}
func main() {
	fmt.Println(climbStairs(2))
	fmt.Println(climbStairs(3))
	fmt.Println(climbStairs(4))
	fmt.Println(climbStairs(5))
	fmt.Println(climbStairs(6))
	fmt.Println(climbStairs(7))
	fmt.Println(climbStairs(8))
	fmt.Println(climbStairs(44))
}

// @lc code=end
