/*
 * @lc app=leetcode id=7 lang=golang
 *
 * [7] Reverse Integer
 */
// package main

// import (
// 	"fmt"
// 	"math"
// )

// @lc code=start
func reverse(x int) int {
	ret := 0
	minLongetstVal := 1000000000
	lowestNumber := x % 10
	if lowestNumber < 0 {
		lowestNumber = -1 * lowestNumber
	}
	if lowestNumber > 1 && (x > minLongetstVal || x < 0-minLongetstVal) {
		// after transfer may over inter scope
		if lowestNumber > 2 {
			return 0
		}
		// lowestNumber == 2
		noHighestNumberVal := x / 10
		reverseNoHighestNumberVal := reverse(noHighestNumberVal)
		if reverseNoHighestNumberVal > (math.MaxInt32%minLongetstVal) || reverseNoHighestNumberVal < (math.MinInt32%minLongetstVal) {
			return 0
		}
	}
	for x != 0 {
		ret = (x % 10) + ret*10
		x = x / 10
	}
	return ret
}

// func main() {
// 	fmt.Println((math.MinInt32 % 1000000000))
// 	fmt.Println(reverse(123))
// 	fmt.Println(reverse(-123))
// 	fmt.Println(reverse(math.MaxInt32))
// 	fmt.Println(reverse(math.MinInt32))
// }

// @lc code=end
