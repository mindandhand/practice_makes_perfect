/*
 * @lc app=leetcode id=69 lang=golang
 *
 * [69] Sqrt(x)
 */
package main

import "fmt"

// @lc code=start
func mySqrt(x int) int {
	i := 1
	for i*i < x {
		i = i * 2
	}
	start := i / 2
	end := i
	for start <= end {
		mid := (start + end) / 2
		tmp1 := mid * mid
		tmp2 := (mid + 1) * (mid + 1)
		if tmp1 <= x && tmp2 > x {
			return mid
		} else if tmp2 == x {
			return mid + 1
		} else if tmp2 < x {
			if start == mid {
				start++
			} else {
				start = mid
			}
		} else {
			end = mid
		}

	}
	return start
}

func main() {
	fmt.Println(mySqrt(1))
	fmt.Println(mySqrt(4))
	fmt.Println(mySqrt(9))
	fmt.Println(mySqrt(17))
	fmt.Println(mySqrt(1000001))
}

// @lc code=end
