/*
 * @lc app=leetcode id=235 lang=golang
 *
 * [235] Lowest Common Ancestor of a Binary Search Tree
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val   int
 *     Left  *TreeNode
 *     Right *TreeNode
 * }
 */

func lowestCommonAncestor(root, p, q *TreeNode) *TreeNode {
	var p_ancestors_array []*TreeNode
	var q_ancestors_array []*TreeNode
	compare_node := root
	for {
		p_ancestors_array = append(p_ancestors_array, compare_node)
		if compare_node.Val == p.Val {
			break
		} else if compare_node.Val < p.Val {
			compare_node = compare_node.Right
		} else {
			compare_node = compare_node.Left
		}
	}
	compare_node = root
	for {
		q_ancestors_array = append(q_ancestors_array, compare_node)
		if compare_node.Val == q.Val {
			break
		} else if compare_node.Val < q.Val {
			compare_node = compare_node.Right
		} else {
			compare_node = compare_node.Left
		}
	}
	i := 0
	for i < len(p_ancestors_array) && i < len(q_ancestors_array) && p_ancestors_array[i] == q_ancestors_array[i] {
		i++
	}
	return p_ancestors_array[i-1]
}

// @lc code=end

