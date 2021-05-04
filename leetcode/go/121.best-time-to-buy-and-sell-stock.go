/*
 * @lc app=leetcode id=121 lang=golang
 *
 * [121] Best Time to Buy and Sell Stock
 */

// @lc code=start
func maxProfit(prices []int) int {
	ret := 0
	length := len(prices)
	buy := 0
	for i := 1; i < length; i++ {
		profit := prices[i] - prices[buy]
		if profit > ret {
			ret = profit
		} else if profit < 0 {
			buy = i
		}
	}
	return ret
}

// @lc code=end

