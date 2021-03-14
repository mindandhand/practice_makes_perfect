/*
 * @lc app=leetcode id=12 lang=golang
 *
 * [12] Integer to Roman
 */
// package main

// import "fmt"

// @lc code=start
func intToRoman(num int) string {
	ret := ""
	pos := 1
	onePosLetter := ""
	tenPosLetter := ""
	fivePosLetter := ""
	for num > 0 {
		switch pos {
		case 1:
			onePosLetter = "I"
			tenPosLetter = "X"
			fivePosLetter = "V"
			break
		case 10:
			onePosLetter = "X"
			tenPosLetter = "C"
			fivePosLetter = "L"
			break
		case 100:
			onePosLetter = "C"
			tenPosLetter = "M"
			fivePosLetter = "D"
			break
		default:
			onePosLetter = "M"
			tenPosLetter = "C"
			fivePosLetter = "L"
		}
		dealNum := num % 10
		num = num / 10
		pos = pos * 10
		if dealNum >= 1 && dealNum <= 3 {
			for dealNum > 0 {
				dealNum--
				ret = onePosLetter + ret
			}
		} else if dealNum == 4 {
			ret = onePosLetter + fivePosLetter + ret
		} else if dealNum >= 5 && dealNum <= 8 {
			dealNum = dealNum - 5
			for dealNum > 0 {
				dealNum--
				ret = onePosLetter + ret
			}
			ret = fivePosLetter + ret
		} else if dealNum == 9 {
			ret = onePosLetter + tenPosLetter + ret

		}
	}
	return ret
}

// func main() {
// 	fmt.Println(intToRoman(3))
// 	fmt.Println(intToRoman(4))
// 	fmt.Println(intToRoman(9))
// 	fmt.Println(intToRoman(58))
// 	fmt.Println(intToRoman(1994))
// }

// @lc code=end
