/*
 * @lc app=leetcode id=463 lang=golang
 *
 * [463] Island Perimeter
 */

// @lc code=start
package main

import "fmt"

func islandPerimeter(grid [][]int) int {
	ret := 0
	len1 := len(grid)
	len2 := len(grid[0])
	for i := 0; i < len1; i++ {
		fmt.Println(ret)
		for j := 0; j < len2; j++ {
			if grid[i][j] == 0 {
				continue
			}
			// top
			if !(i > 0 && grid[i-1][j] == 1) {
				ret++
			}
			// left
			if !(j > 0 && grid[i][j-1] == 1) {
				ret++
			}
			if !(i < len1-1 && grid[i+1][j] == 1) {
				ret++
			}
			if !(j < len2-1 && grid[i][j+1] == 1) {
				ret++
			}
		}
	}
	return ret
}
func main() {
	nums := [][]int{{1}}
	fmt.Println(islandPerimeter(nums))
	nums1 := [][]int{{1, 0}}
	fmt.Println(islandPerimeter(nums1))
	nums2 := [][]int{{0, 1, 0, 0}, {1, 1, 1, 0}, {0, 1, 0, 0}, {1, 1, 0, 0}}
	fmt.Println(islandPerimeter(nums2))
}

// @lc code=end
