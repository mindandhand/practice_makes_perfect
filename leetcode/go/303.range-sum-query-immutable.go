/*
 * @lc app=leetcode id=303 lang=golang
 *
 * [303] Range Sum Query - Immutable
 */

// @lc code=start
type NumArray struct {
	data []int
}

func Constructor(nums []int) NumArray {
	na := NumArray{
		data: nums,
	}
	return na
}

func (this *NumArray) SumRange(left int, right int) int {
	ret := 0
	for i := left; i <= right; i++ {
		ret = ret + this.data[i]
	}
	return ret
}

/**
 * Your NumArray object will be instantiated and called as such:
 * obj := Constructor(nums);
 * param_1 := obj.SumRange(left,right);
 */
// @lc code=end

