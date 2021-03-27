/*
 * @lc app=leetcode id=20 lang=golang
 *
 * [20] Valid Parentheses
 */

package main

import (
	"container/list"
	"fmt"
)

// @lc code=start
func isValid(s string) bool {
	list1 := list.New()
	length := len(s)
	for i := 0; i < length; i++ {
		switch s[i] {
		case '[':
			list1.PushFront(s[i])
			break
		case '(':
			list1.PushFront(s[i])
			break
		case '{':
			list1.PushFront(s[i])
			break
		case ')':
			if list1.Len() >= 1 && list1.Front().Value.(uint8) == '(' {
				list1.Remove(list1.Front())
				break
			} else {
				return false
			}
		case ']':
			if list1.Len() >= 1 && list1.Front().Value.(uint8) == '[' {
				list1.Remove(list1.Front())
				break
			} else {
				return false
			}
		case '}':
			if list1.Len() >= 1 && list1.Front().Value.(uint8) == '{' {
				list1.Remove(list1.Front())
				break
			} else {
				return false
			}
		default:
			return false
		}
	}
	return list1.Len() == 0
}

func main() {
	fmt.Println(isValid("{[]}"))
	fmt.Println(isValid("(){}"))
	fmt.Println(isValid("{[)}"))
}

// @lc code=end
