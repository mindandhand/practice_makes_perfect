/*
 * @lc app=leetcode id=16 lang=golang
 *
 * [16] 3Sum Closest
 */

package main

import (
	"fmt"
	"math"
	"sort"
)

// @lc code=start
func threeSumClosest(nums []int, target int) int {
	ret := 0
	diff_val_close := math.MaxInt64
	length := len(nums)
	sort.Ints(nums)
	for i := 0; i < length-2; i++ {

		for j := i + 1; j < length-1; j++ {

			for k := j + 1; k < length; k++ {

				diff_val := (nums[i] + nums[j] + nums[k] - target)
				if diff_val < 0 {
					diff_val = diff_val * -1
				}
				fmt.Println(nums[i], nums[j], nums[k])
				fmt.Println("diff val:", diff_val)
				if diff_val <= diff_val_close {
					ret = nums[i] + nums[j] + nums[k]
					diff_val_close = diff_val
				} 
				for k+1 < length && nums[k+1] == nums[k] {
					k++
				}
			}
			for j+1 < length && nums[j+1] == nums[j] {
				j++
			}
		}
		for i+1 < length && nums[i+1] == nums[i] {
			i++
		}
	}
	return ret
}

func main() {
	var numbers []int
	numbers = append(numbers, 1)
	numbers = append(numbers, 2)
	numbers = append(numbers, 4)
	numbers = append(numbers, 8)
	numbers = append(numbers, 16)
	numbers = append(numbers, 32)
	numbers = append(numbers, 64)
	numbers = append(numbers, 128)
	fmt.Println(threeSumClosest(numbers, 82))

}

// @lc code=end
