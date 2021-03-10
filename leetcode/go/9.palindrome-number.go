/*
 * @lc app=leetcode id=9 lang=golang
 *
 * [9] Palindrome Number
 */

// @lc code=start
func isPalindrome(x int) bool {
	if x < 0 {
		return false
	}
	var digits []int
	for x > 0 {
		digits = append(digits, x%10)
		x = x / 10
	}
	length := len(digits)
	for i := length/2 - 1; i >= 0; i-- {
		if digits[i] != digits[length-1-i] {
			return false
		}

	}
	return true
}

// @lc code=end

