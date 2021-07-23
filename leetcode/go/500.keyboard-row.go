/*
 * @lc app=leetcode id=500 lang=golang
 *
 * [500] Keyboard Row
 */
package main

import "strings"

func isKeyboardWord(dict map[byte]int, word string) bool {
	word = strings.ToLower(word)
	row := dict[word[0]]
	for i := 1; i < len(word); i++ {
		if dict[word[i]] != row {
			return false
		}
	}
	return true
}

// @lc code=start
func findWords(words []string) []string {
	dict := make(map[byte]int)
	first_keys := "qwertyuiop"
	second_keys := "asdfghjkl"
	third_keys := "zxcvbnm"
	for i := 0; i < len(first_keys); i++ {
		dict[first_keys[i]] = 1
	}
	for i := 0; i < len(second_keys); i++ {
		dict[second_keys[i]] = 2
	}
	for i := 0; i < len(third_keys); i++ {
		dict[third_keys[i]] = 3
	}

	var ret []string
	length := len(words)
	for i := 0; i < length; i++ {
		if isKeyboardWord(dict, words[i]) {
			ret = append(ret, words[i])
		}
	}
	return ret
}

// @lc code=end
