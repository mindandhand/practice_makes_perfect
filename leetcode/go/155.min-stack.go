/*
 * @lc app=leetcode id=155 lang=golang
 *
 * [155] Min Stack
 */

type Node struct {
	min  int
	data int
	Next *Node
}

// @lc code=start
type MinStack struct {
	head *Node
}

/** initialize your data structure here. */
func Constructor() MinStack {
	return MinStack{
		head: nil,
	}
}

func (this *MinStack) Push(val int) {
	if this.head == nil {
		this.head = &Node{
			min:  val,
			data: val,
			Next: nil,
		}
	} else {
		new_node := &Node{
			data: val,
			Next: this.head,
		}
		if val < this.head.min {
			new_node.min = val
		} else {
			new_node.min = this.head.min
		}
		this.head = new_node
	}
}

func (this *MinStack) Pop() {
	this.head = this.head.Next
}

func (this *MinStack) Top() int {
	return this.head.data
}

func (this *MinStack) GetMin() int {
	return this.head.min
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


