/*
 * @lc app=leetcode id=34 lang=golang
 *
 * [34] Find First and Last Position of Element in Sorted Array
 */
package main

import "fmt"

// @lc code=start
func searchRange(nums []int, target int) []int {
	var ret []int
	length := len(nums)
	if length == 0 {
		ret = append(ret, -1)
		ret = append(ret, -1)
		return ret
	}
	start := 0
	end := length - 1
	find := false
	mid := (start + end) / 2
	for start <= end {
		mid = (start + end) / 2
		if nums[mid] > target {
			end = mid
		} else if nums[mid] < target {
			if start == mid {
				start++
				if start < length && nums[start] == target {
					mid = start
					find = true
				} else if start < length && nums[end] == target {
					mid = end
					find = true
				}
			} else {
				start = mid
			}

		} else {
			find = true
			break
		}
		if start == end {
			break
		}
	}
	if find {
		start = 0
		end = mid
		if start == end {
			ret = append(ret, start)
		} else {
			for start != end {
				mid1 := (start + end) / 2
				if nums[mid1] >= target {
					end = mid1
				} else {
					if start == mid1 {
						ret = append(ret, start+1)
						break
					}
					start = mid1
				}
				if start == end {
					ret = append(ret, end)
				}
			}
		}

		start = mid
		end = length - 1
		if start == end {
			ret = append(ret, start)
		} else {
			for start != end {
				mid1 := (start + end) / 2
				if nums[mid1] <= target {
					if start == mid1 {
						start++
					} else {
						start = mid1
					}
				} else {
					end = mid1
				}
				if start == end {
					if nums[end] == target {
						ret = append(ret, end)
					} else {
						ret = append(ret, end-1)
					}
				}
			}
		}
	} else {
		ret = append(ret, -1)
		ret = append(ret, -1)
		return ret
	}
	return ret
}

func main() {
	// var nums = []int{5, 7, 7, 8, 8, 10}
	var nums1 = []int{2}
	var nums2 = []int{2, 2}
	// fmt.Println(searchRange(nums, 6))
	// fmt.Println(searchRange(nums, 5))
	// fmt.Println(searchRange(nums, 7))
	// fmt.Println(searchRange(nums, 10))
	fmt.Println(searchRange(nums1, 2))
	fmt.Println(searchRange(nums2, 2))
}

// @lc code=end
