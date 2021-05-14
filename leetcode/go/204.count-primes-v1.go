/*
 * @lc app=leetcode id=204 lang=golang
 *
 * [204] Count Primes
 */
package main

import (
	"fmt"
	"math"
)

// @lc code=start
func countPrimes(n int) int {
	ret := 0
	if n <= 2 {
		return ret
	}
	var primes []int
	primes = append(primes, 2)
	for i := 3; i < n; i++ {
		loop_end := math.Sqrt(float64(n))
		j := 0
		loop_on := true
		for ; loop_on && j < len(primes) && float64(primes[j]) <= loop_end; j++ {
			if i%primes[j] == 0 {
				loop_on = false
				break
			}
		}
		if loop_on {
			primes = append(primes, i)
		}
	}
	// fmt.Println(primes)
	return len(primes)
}

func main() {
	fmt.Println(countPrimes(0))
	fmt.Println(countPrimes(1))
	fmt.Println(countPrimes(10))
}

// @lc code=end
