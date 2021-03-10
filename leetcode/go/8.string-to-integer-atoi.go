/*
 * @lc app=leetcode id=8 lang=golang
 *
 * [8] String to Integer (atoi)
 */
package main

import (
	"fmt"
)

// @lc code=start
func myAtoi(s string) int {
	ret := 0
	if len(s) == 0 {
		return ret
	}
	flag := 0
	hasLetterBefore := false
	i := 0
	length := len(s)
	for i < length && s[i] == ' ' {
		i++
	}

	for i < length {
		if s[i] == '+' && flag == 0 {
			if hasLetterBefore {
				break
			}
			flag = 1
		} else if s[i] == '-' && flag == 0 {
			if hasLetterBefore {
				break
			}
			flag = -1
		} else if s[i] >= '0' && s[i] <= '9' {
			if flag == -1 && (ret > 214748364 || (ret == 214748364 && s[i] >= 56)) {
				return -2147483648
			} else if flag != -1 && (ret > 214748364 || (ret == 214748364 && s[i] >= 55)) {
				return 2147483647
			}
			ret = ret*10 + (int(s[i]) - 48)
			hasLetterBefore = true
		} else {
			break
		}
		i++

	}
	if flag == 0 {
		return ret
	}
	return ret * flag
}

func main() {
	fmt.Println(myAtoi("442"))
	fmt.Println(myAtoi("   -42"))
	fmt.Println(myAtoi("4193 with words"))
	fmt.Println(myAtoi("words and 987"))
	fmt.Println(myAtoi("-91283472332"))
	fmt.Println(myAtoi("21474836460"))
	fmt.Println(myAtoi("00000-42a1234"))
	fmt.Println(myAtoi("2147483646"))
	fmt.Println(myAtoi("-2147483647"))
}

// @lc code=end
