/*
 * @lc app=leetcode id=205 lang=golang
 *
 * [205] Isomorphic Strings
 */
package main

import "fmt"

// @lc code=start
func isIsomorphic(s string, t string) bool {
	var s_map = make(map[byte]int)
	var t_map = make(map[byte]int)

	count := 0
	s_mode := ""
	for i := 0; i < len(s); i++ {
		if _, ok := s_map[s[i]]; ok {
			s_mode = s_mode + fmt.Sprint(s_map[s[i]])
		} else {
			count++
			s_map[s[i]] = count
			s_mode = s_mode + fmt.Sprint(count)
		}
	}

	count = 0
	t_mode := ""
	for i := 0; i < len(t); i++ {
		if _, ok := t_map[t[i]]; ok {
			t_mode = t_mode + fmt.Sprint(t_map[t[i]])
		} else {
			count++
			t_map[t[i]] = count
			t_mode = t_mode + fmt.Sprint(count)
		}
	}
	return t_mode == s_mode
}

// func main() {
// 	fmt.Println(isIsomorphic("123", "321"))
// 	fmt.Println(isIsomorphic("egg", "add"))
// 	fmt.Println(isIsomorphic("foo", "bar"))
// 	fmt.Println(isIsomorphic("paper", "title"))
// }

// @lc code=end
