/*
 * @lc app=leetcode id=67 lang=golang
 *
 * [67] Add Binary
 */
package main

import "fmt"

// @lc code=start
func addBinary(a string, b string) string {
	var ret string
	i := len(a) - 1
	j := len(b) - 1
	flag := false
	for i >= 0 || j >= 0 {
		sum := 0
		if i >= 0 {
			sum = sum + int(a[i]-'0')
		}
		if j >= 0 {
			sum = sum + int(b[j]-'0')
		}
		if flag {
			sum = sum + 1
		}
		if sum/2 == 1 {
			flag = true
		} else {
			flag = false
		}
		if sum%2 == 1 {
			ret = "1" + ret
		} else {
			ret = "0" + ret
		}
		i--
		j--
	}

	if flag {
		ret = "1" + ret
	}
	return ret
}

func main() {
	// fmt.Println(addBinary("11", "1"))
	fmt.Println(addBinary("1010", "1011"))
	// fmt.Println(addBinary("1", "111"))
}

// @lc code=end
