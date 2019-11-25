// Complexity O(n^4), TLE :(

package main

import "fmt"

var i = 0

func main() {
	fmt.Println(minDistance("1234567890", "1234567890"))
	fmt.Println(i)
}

func minDistance(word1 string, word2 string) int {
	if len(word1) == 0 {
		return len(word2)
	}
	if len(word2) == 0 {
		return len(word1)
	}
	cache := make(map[[2]string]int)
	return minD([]byte(word1), []byte(word2), cache)
}

func minD(a []byte, b []byte, cache map[[2]string]int) int {
	i++
	if t, ok := cache[[2]string{string(a), string(b)}]; ok {
		return t
	}
	if len(a) == 1 && len(b) == 1 {
		if a[0] == b[0] {
			return 0
		}
		return 1
	}
	if len(a) == 1 {
		for _, k := range b {
			if k == a[0] {
				return len(b) - 1
			}
		}
		return len(b)
	}
	if len(b) == 1 {
		for _, k := range a {
			if k == b[0] {
				return len(a) - 1
			}
		}
		return len(a)
	}

	ans := 1 << 30
	for i := 1; i < len(a); i++ {
		for j := 1; j < len(b); j++ {
			ans = min(ans, minD(a[:i], b[:j], cache)+minD(a[i:], b[j:], cache))
		}
	}
	cache[[2]string{string(a), string(b)}] = ans
	return ans
}

func min(a int, b int) int {
	if a > b {
		return b
	}
	return a
}
