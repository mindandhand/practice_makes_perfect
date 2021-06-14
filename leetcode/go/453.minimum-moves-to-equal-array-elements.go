/*
 * @lc app=leetcode id=453 lang=golang
 *
 * [453] Minimum Moves to Equal Array Elements
 */

// @lc code=start
func minMoves(nums []int) int {
	//sum(X1 + ...Xn) + y(N-1) = X*N
	// X - Xmin = y ==> X=y+Xmin
	// sum(X1+...Xn) + y(N-1) = (y+Xmin)N
	// y = sum(X1 + ...Xn) - Xmin*N

	i := 0
	length := len(nums)
	sum := 0
	min := 0
	for ; i < length; i++ {
		if nums[i] < nums[min] {
			min = i
		}
		sum = sum + nums[i]
	}
	return sum - nums[min]*length
}

// @lc code=end

