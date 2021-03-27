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

	dict := make(map[string]int)
	var ret [][]int
	length := len(nums)
	if length < 3 {
		return ret
	}
	i := 0
	sort.Ints(nums)
	var new_nums []int
	for i = 0; i < length; {
		if nums[i] == 0 && i+2 < length && nums[i+2] == 0 {
			new_nums = append(new_nums, 0)
			i++
			new_nums = append(new_nums, 0)
			i++
			new_nums = append(new_nums, 0)
			i++
			for i < length-1 && nums[i] == nums[i-1] {
				i++
			}
		} else if i+1 < length && nums[i+1] == nums[i] {
			new_nums = append(new_nums, nums[i])
			i++
			new_nums = append(new_nums, nums[i])
			i++
			for i < length-1 && nums[i] == nums[i-1] {
				i++
			}
		} else {
			new_nums = append(new_nums, nums[i])
			i++
		}
	}
	nums = new_nums
	length = len(nums)
	for i = 0; i < length-2; i++ {
		for j := i + 1; j < length-1; j++ {
			for k := j + 1; k <= length-1; k++ {
				if nums[i]+nums[j]+nums[k] == 0 {
					key := fmt.Sprintf("%d", nums[i]) + "_" + fmt.Sprintf("%d", nums[j]) + "_" + fmt.Sprintf("%d", nums[k])
					_, ok := dict[key]
					if ok {
						k++
						continue
					} else {
						dict[key] = 1
					}
					var matchArr []int
					matchArr = append(matchArr, nums[i])
					matchArr = append(matchArr, nums[j])
					matchArr = append(matchArr, nums[k])
					ret = append(ret, matchArr)
				}
			}
		}
	}
	return ret
}

func main() {
	var numbers []int
	fmt.Println(threeSum(numbers))
	numbers = append(numbers, 0)
	fmt.Println(threeSum(numbers))
	numbers = append(numbers, -1)
	numbers = append(numbers, 1)
	numbers = append(numbers, 2)
	numbers = append(numbers, -1)
	numbers = append(numbers, -4)
	fmt.Println(threeSum(numbers))
	var numbers2 []int
	for i := 0; i < 1000; i++ {
		numbers2 = append(numbers2, 0)
	}
	for i := 0; i < 1000; i++ {
		numbers2 = append(numbers2, 1)
	}
	for i := 0; i < 1000; i++ {
		numbers2 = append(numbers2, -1)
	}
	fmt.Println(threeSum(numbers2))

}

// @lc code=end
