/*
 * @lc app=leetcode id=66 lang=golang
 *
 * [66] Plus One
 */
package main

import "fmt"

// @lc code=start
func plusOne(digits []int) []int {
	ret := make([]int, len(digits)+1)
	pos := len(digits) - 1
	plus_one := true
	for pos >= 0 {
		if digits[pos] == 9 && plus_one {
			ret[pos+1] = 0

		} else if plus_one {
			plus_one = false
			ret[pos+1] = digits[pos] + 1
		} else {
			ret[pos+1] = digits[pos]
		}
		pos--
	}
	if plus_one {
		ret[0] = 1
		return ret
	} else {
		return ret[1:]
	}
}

func main() {
	arr1 := []int{1, 1, 2}
	fmt.Println(plusOne(arr1))
	arr2 := []int{9, 9}
	fmt.Println(plusOne(arr2))
	arr3 := []int{8, 9, 9, 9}
	fmt.Println(plusOne(arr3))
}

// @lc code=end
