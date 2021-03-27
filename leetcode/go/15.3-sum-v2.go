/*
 * @lc app=leetcode id=15 lang=golang
 *
 * [15] 3Sum
 */
package main

import (
	"fmt"
	"sort"
)

// @lc code=start
func threeSum(nums []int) [][]int {
	var ret [][]int
	length := len(nums)
	if length < 3 {
		return ret
	}
	i := 0
	sort.Ints(nums)
	for i = 0; i < length-2; i++ {
		for j := i + 1; j < length-1; j++ {
			for k := length - 1; k > j; k-- {
				numSum := nums[i] + nums[j] + nums[k]
				if numSum == 0 {
					var matchArr []int
					matchArr = append(matchArr, nums[i])
					matchArr = append(matchArr, nums[j])
					matchArr = append(matchArr, nums[k])
					ret = append(ret, matchArr)
				}
				if numSum < 0 {
					break
				}
				for k-1 > j && nums[k] == nums[k-1] {
					k--
				}

			}
			for j+1 < length-1 && nums[j] == nums[j+1] {
				j++
			}

		}
		for i+1 < length-2 && nums[i] == nums[i+1] {
			i++
		}
	}
	return ret
}
func main() {
	var numbers []int
	fmt.Println(threeSum(numbers))
	numbers = append(numbers, 0)
	fmt.Println(threeSum(numbers))
	numbers = append(numbers, -2)
	numbers = append(numbers, 1)
	numbers = append(numbers, 2)
	numbers = append(numbers, 1)
	fmt.Println(threeSum(numbers))
	// var numbers2 []int
	// for i := 0; i < 1000; i++ {
	// 	numbers2 = append(numbers2, 0)
	// }
	// for i := 0; i < 1000; i++ {
	// 	numbers2 = append(numbers2, 1)
	// }
	// for i := 0; i < 1000; i++ {
	// 	numbers2 = append(numbers2, -1)
	// }
	// fmt.Println(threeSum(numbers2))

}

// @lc code=end
