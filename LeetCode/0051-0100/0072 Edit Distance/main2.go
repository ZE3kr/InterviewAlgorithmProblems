// Complexity O(n^2), AC :)

package main

import "fmt"

func main() {
	fmt.Println(minDistance("pneumonoultramicroscopicsilicovolcanoconiosis", "ultramicroscopically"))
}

func minDistance(word1 string, word2 string) int {
	if len(word1) == 0 {
		return len(word2)
	}
	if len(word2) == 0 {
		return len(word1)
	}
	cache := make(map[[2]int]int)
	return minD([]byte(word1), []byte(word2), 0, 0, cache)
}

func minD(a []byte, b []byte, x int, y int, cache map[[2]int]int) int {
	if t, ok := cache[[2]int{x, y}]; ok {
		return t
	}
	if len(a)-1 == x && len(b)-1 == y {
		if a[x] == b[y] {
			return 0
		}
		return 1
	}
	if len(a)-1 == x {
		for _, k := range b[y:] {
			if k == a[x] {
				return len(b) - y - 1
			}
		}
		return len(b) - y
	}
	if len(b)-1 == y {
		for _, k := range a[x:] {
			if k == b[y] {
				return len(a) - x - 1
			}
		}
		return len(a) - x
	}

	if a[x] == b[y] {
		cache[[2]int{x, y}] = minD(a, b, x+1, y+1, cache)
	} else {
		cache[[2]int{x, y}] = 1 + min(minD(a, b, x+1, y, cache), min(minD(a, b, x, y+1, cache), minD(a, b, x+1, y+1, cache)))
	}
	return cache[[2]int{x, y}]
}

func min(a int, b int) int {
	if a > b {
		return b
	}
	return a
}
