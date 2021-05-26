/*
 * @lc app=leetcode id=412 lang=golang
 *
 * [412] Fizz Buzz
 */

// @lc code=start
func fizzBuzz(n int) []string {
	var ret []string
	for i := 1; i <= n; i++ {
		if i%3 == 0 {
			if i%5 == 0 {
				ret = append(ret, "FizzBuzz")
			} else {
				ret = append(ret, "Fizz")
			}
		} else if i%5 == 0 {
			ret = append(ret, "Buzz")
		} else {
			ret = append(ret, fmt.Sprint(i))
		}
	}
	return ret
}

// @lc code=end

