/*
 * @lc app=leetcode id=495 lang=golang
 *
 * [495] Teemo Attacking
 */

// @lc code=start
func findPoisonedDuration(timeSeries []int, duration int) int {
	ret := 0
	length := len(timeSeries) - 2
	for i := 0; i <= length; i++ {
		gap := timeSeries[i+1] - timeSeries[i]
		if gap < duration {
			ret = ret + gap
		} else {
			ret = ret + duration
		}
	}
	if len(timeSeries) > 0 {
		ret = ret + duration
	}
	return ret
}

// @lc code=end

