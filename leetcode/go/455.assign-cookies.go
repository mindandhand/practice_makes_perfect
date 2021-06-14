/*
 * @lc app=leetcode id=455 lang=golang
 *
 * [455] Assign Cookies
 */
package main

import "sort"

// @lc code=start
func findContentChildren(g []int, s []int) int {
	ret := 0
	sort.Ints(g)
	sort.Ints(s)
	i := 0
	len1 := len(g)
	j := 0
	len2 := len(s)
	for j < len2 && s[j] < s[i] {
		j++
	}
	for i < len1 && j < len2 {
		if s[j] < g[i] {
			j++
			continue
		} else {
			i++
			j++
			ret++
		}
	}
	return ret
}
func main() {

}

// @lc code=end
