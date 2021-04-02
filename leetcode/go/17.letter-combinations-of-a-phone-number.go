/*
 * @lc app=leetcode id=17 lang=golang
 *
 * [17] Letter Combinations of a Phone Number
 */
package main

import (
	"fmt"
	"strings"
)

func getNumberLetters(digit byte) int {
	if digit == '7' || digit == '9' {
		return 4
	} else {
		return 3
	}
}

func getLetterDistanceFromStart(digit byte) int {

	if digit == '8' || digit == '9' {
		return 3*int(digit-'2') + 1
	}
	return 3 * int(digit-'2')
}

// @lc code=start
func letterCombinations(digits string) []string {
	var ret []string
	length := len(digits)
	var pos_arr = make([]int, len(digits))
	if length > 0 {

		total := 1
		for i := 0; i < length; i++ {
			total = total * getNumberLetters(digits[i])
			pos_arr[i] = 0
		}

		var str strings.Builder
		for i := 0; i < total; i++ {
			str.Reset()
			for j := 0; j < length; j++ {
				str.WriteByte(byte(int('2') + getLetterDistanceFromStart(digits[j]) + pos_arr[j] + 47))
			}
			if pos_arr[length-1]+1 == getNumberLetters(digits[length-1]) {
				// high plus 1
				pos_arr[length-1] = 0
				loop := length - 2
				high_add_one := true
				for loop >= 0 && high_add_one {
					if pos_arr[loop]+1 == getNumberLetters(digits[loop]) {
						pos_arr[loop] = 0
						high_add_one = true
					} else {
						pos_arr[loop]++
						high_add_one = false
					}
					loop--
				}
			} else {
				pos_arr[length-1]++
			}

			ret = append(ret, str.String())
		}
	}
	return ret
}

func main() {
	fmt.Println(letterCombinations(""))
	fmt.Println(letterCombinations("2"))
	fmt.Println(letterCombinations("238"))
	fmt.Println(letterCombinations("237"))
}

// @lc code=end
