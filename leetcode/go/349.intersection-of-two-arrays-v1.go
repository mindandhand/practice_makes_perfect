/*
 * @lc app=leetcode id=349 lang=golang
 *
 * [349] Intersection of Two Arrays
 */
func intersection(nums1 []int, nums2 []int) []int {
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
			if len(ret) == 0 || nums1[i] != ret[len(ret)-1] {
				ret = append(ret, nums1[i])
			}
			i++
			j++
		}
	}
	return ret
}

// @lc code=end
