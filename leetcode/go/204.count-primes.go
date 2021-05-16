/*
 * @lc app=leetcode id=204 lang=golang
 *
 * [204] Count Primes
 */

// @lc code=start
package main

import (
	"fmt"
)

func countPrimes(n int) int {
	ret := 0
	if n <= 2 {
		return ret
	}
	not_primes := make([]bool, n)
	for i := 2; i < n; i++ {
		if !not_primes[i] {
			ret++
		}
		for j := i + i; j < n; j = j + i {
			not_primes[j] = true
		}
	}
	return ret
}

func main() {
	fmt.Println(countPrimes(10))
}

// @lc code=end
