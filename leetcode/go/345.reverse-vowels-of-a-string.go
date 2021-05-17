/*
 * @lc app=leetcode id=345 lang=golang
 *
 * [345] Reverse Vowels of a String
 */
func isVowel(b byte) bool {
	if b == 'a' || b == 'A' || b == 'e' || b == 'E' || b == 'i' || b == 'I' || b == 'o' || b == 'O' || b == 'u' || b == 'U' {
		return true
	}
	return false
}

// @lc code=start
func reverseVowels(s string) string {
	xBytes := []byte(s)
	start := 0
	end := len(s) - 1
	for start < end {
		for start < end && !(isVowel(xBytes[start])) {
			start++
		}
		for start < end && !(isVowel(xBytes[end])) {
			end--
		}
		if start < end {
			tmp := xBytes[start]
			xBytes[start] = xBytes[end]
			xBytes[end] = tmp
			start++
			end--
		}
	}
	return string(xBytes)
}

// @lc code=end
