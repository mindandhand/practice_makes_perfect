/*
 * @lc app=leetcode id=4 lang=golang
 *
 * [4] Median of Two Sorted Arrays
 */

// @lc code=start
func findMedianSortedArrays(nums1 []int, nums2 []int) float64 {
	len1 := len(nums1)
	len2 := len(nums2)
	len := len1 + len2
	var halfLen int
	midIntNum := 1
	midInt1 := 0
	if len%2 == 0 {
		midIntNum = 2
		halfLen = len/2 - 1
	} else {
		halfLen = (len - 1) / 2
	}
	k := 0
	i := 0
	j := 0
	for k <= halfLen {

		if i >= len1 || (j < len2 && nums1[i] > nums2[j]) {

			if k == halfLen {
				midInt1 = nums2[j]
			}
			j++

		} else {

			if k == halfLen {
				midInt1 = nums1[i]
			}
			i++
		}
		k++
	}
	if midIntNum == 1 {
		return float64(midInt1)
	}
	if i >= len1 || (j < len2 && nums2[j] < nums1[i]) {
		return float64((midInt1 + nums2[j])) / 2
	} else {
		return float64((midInt1 + nums1[i])) / 2
	}
}

// @lc code=end
