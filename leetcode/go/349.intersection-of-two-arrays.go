/*
 * @lc app=leetcode id=349 lang=golang
 *
 * [349] Intersection of Two Arrays
 */

// @lc code=start
func intersection(nums1 []int, nums2 []int) []int {
	var ret []int
	rmap := make(map[int]int)
	for i := 0; i < len(nums1); i++ {
		rmap[nums1[i]] = 1
	}

	for i := 0; i < len(nums2); i++ {
		if _, ok := rmap[nums2[i]]; ok {
			ret = append(ret, nums2[i])
			delete(rmap, nums2[i])
		}
	}
	return ret
}

// @lc code=end

