/*
 * @lc app=leetcode id=492 lang=golang
 *
 * [492] Construct the Rectangle
 */

package main

import "math"

// @lc code=start
func constructRectangle(area int) []int {
	var ret []int
	loop := int(math.Sqrt(float64(area)))
	for loop >= 1 {
		if area%loop == 0 {
			ret = append(ret, area/loop)
			ret = append(ret, loop)
			return ret
		}
		loop--
	}
	return ret
}

func main() {

}

// @lc code=end
