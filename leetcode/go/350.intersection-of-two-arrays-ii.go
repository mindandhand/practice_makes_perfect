/*
 * @lc app=leetcode id=350 lang=golang
 *
 * [350] Intersection of Two Arrays II
 */

// @lc code=start
func intersect(nums1 []int, nums2 []int) []int {
	var ret []int
	sort.Ints(nums1)
	sort.Ints(nums2)
	len1 := len(nums1)
	len2 := len(nums2)
	j := 0
	i := 0
	for i < len1 && j < len2 {
		if nums1[i] < nums2[j] {
			i++
		} else if nums1[i] > nums2[j] {
			j++
		} else {
			ret = append(ret, nums1[i])
			i++
			j++
		}
	}
	return ret
}

// @lc code=end

