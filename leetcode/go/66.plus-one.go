/*
 * @lc app=leetcode id=66 lang=golang
 *
 * [66] Plus One
 */
package main

import "fmt"

// @lc code=start
func plusOne(digits []int) []int {
	for i := len(digits) - 1; i >= 0; i-- {
		if digits[i] != 9 {
			digits[i]++
			return digits
		}
		digits[i] = 0
	}
	ret := make([]int, len(digits)+1)
	ret[0] = 1
	return ret
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
