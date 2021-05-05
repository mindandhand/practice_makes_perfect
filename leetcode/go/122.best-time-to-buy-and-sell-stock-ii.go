/*
 * @lc app=leetcode id=122 lang=golang
 *
 * [122] Best Time to Buy and Sell Stock II
 */

// @lc code=start
func maxProfit(prices []int) int {
	ret := 0
	length := len(prices)
	buy := 0
	i := 1
	for ; i < length; i++ {
		if prices[i] > prices[buy] && prices[i] >= prices[i-1] {
			continue
		}
		if prices[i] <= prices[i-1] {
			fmt.Println(prices[i-1] - prices[buy])
			ret = ret + prices[i-1] - prices[buy]
			buy = i
		}

	}
	if length >= 2 && prices[length-1] >= prices[length-2] {
		fmt.Println(prices[length-1] - prices[buy])
		ret = ret + prices[length-1] - prices[buy]
	}
	return ret
}

// @lc code=end

