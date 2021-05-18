/*
 * @lc app=leetcode id=374 lang=golang
 *
 * [374] Guess Number Higher or Lower
 */

// @lc code=start
/**
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is lower than the guess number
 *			      1 if num is higher than the guess number
 *               otherwise return 0
 * func guess(num int) int;
 */
func guessNumber(n int) int {
	max := n
	min := 1
	mid := 1
	for min < max {
		mid = int((max + min) / 2)
		ret := guess(mid)
		fmt.Println(ret)
		if ret == 0 {
			return mid
		} else if ret > 0 {

			if min == mid {
				min++
				mid = min
			} else {
				min = mid
			}

		} else {
			max = mid
		}
	}
	return mid
}

// @lc code=end
