/*
 * @lc app=leetcode id=13 lang=golang
 *
 * [13] Roman to Integer
 */

package main

import "fmt"

// @lc code=start
func romanToInt(s string) int {
	ret := 0
	length := len(s) - 1
	for length >= 0 {
		switch s[length] {
		case 'I':
			ret = ret + 1
			length = length - 1
			break
		case 'V':
			if length >= 1 && s[length-1] == 'I' {
				ret = ret + 4
				length = length - 2
			} else {
				ret = ret + 5
				length = length - 1
			}
			break
		case 'X':
			if length >= 1 && s[length-1] == 'I' {
				ret = ret + 9
				length = length - 2
			} else {
				ret = ret + 10
				length = length - 1
			}
			break
		case 'L':
			if length >= 1 && s[length-1] == 'X' {
				ret = ret + 40
				length = length - 2
			} else {
				ret = ret + 50
				length = length - 1
			}
			break
		case 'C':
			if length >= 1 && s[length-1] == 'X' {
				ret = ret + 90
				length = length - 2
			} else {
				ret = ret + 100
				length = length - 1
			}
			break
		case 'D':
			if length >= 1 && s[length-1] == 'C' {
				ret = ret + 400
				length = length - 2
			} else {
				ret = ret + 500
				length = length - 1
			}

			break
		case 'M':
			if length >= 1 && s[length-1] == 'C' {
				ret = ret + 900
				length = length - 2
			} else {
				ret = ret + 1000
				length = length - 1
			}
			break

		}
	}
	return ret
}

func main() {
	fmt.Println(romanToInt("III"))
	fmt.Println(romanToInt("IV"))
	fmt.Println(romanToInt("IX"))
	fmt.Println(romanToInt("LVIII"))
	fmt.Println(romanToInt("MCMXCIV"))
}

// @lc code=end
