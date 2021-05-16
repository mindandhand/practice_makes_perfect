/*
 * @lc app=leetcode id=278 lang=golang
 *
 * [278] First Bad Version
 */

// @lc code=start
/**
 * Forward declaration of isBadVersion API.
 * @param   version   your guess about first bad version
 * @return 	 	      true if current version is bad
 *			          false if current version is good
 * func isBadVersion(version int) bool;
 */

func firstBadVersion(n int) int {
	max := math.MaxInt32
	min := 1
	for min < max {
		mid := int((max + min) / 2)
		if isBadVersion(mid) {
			max = mid
		} else {
			if min == mid {
				min++
			} else {
				min = mid
			}
		}

	}
	return min
}

// @lc code=end
