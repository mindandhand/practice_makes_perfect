/*
 * @lc app=leetcode id=155 lang=golang
 *
 * [155] Min Stack
 */
package main

import "container/list"

// @lc code=start
type MinStack struct {
	data  list.List
	order list.List
}

/** initialize your data structure here. */
func Constructor() MinStack {
	return MinStack{
		data:  list.List{},
		order: list.List{},
	}
}

func (this *MinStack) Push(val int) {
	this.data.PushFront(val)
	order_loop := this.order.Front()
	for order_loop != nil {
		if order_loop.Value.(int) > val {
			this.order.InsertBefore(val, order_loop)
			return
		}
		order_loop = order_loop.Next()
	}
	this.order.PushBack(val)
}

func (this *MinStack) Pop() {
	if this.data.Len() <= 0 {
		return
	}
	val := this.data.Front().Value.(int)
	order_loop := this.order.Front()
	for order_loop != nil {
		if order_loop.Value.(int) == val {
			break
		}
		order_loop = order_loop.Next()
	}
	this.data.Remove(order_loop)
	this.data.Remove(this.data.Front())
}

func (this *MinStack) Top() int {
	return this.data.Front().Value.(int)
}

func (this *MinStack) GetMin() int {
	return this.order.Front().Value.(int)
}

func main() {

}

/**
 * Your MinStack object will be instantiated and called as such:
 * obj := Constructor();
 * obj.Push(val);
 * obj.Pop();
 * param_3 := obj.Top();
 * param_4 := obj.GetMin();
 */
// @lc code=end
