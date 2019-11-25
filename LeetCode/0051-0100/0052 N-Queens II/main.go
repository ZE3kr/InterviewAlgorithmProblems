package main

import (
	"fmt"
)

func main() {
	fmt.Println(totalNQueens(7))
}

func totalNQueens(n int) int {
	return len(dfs(n, []int{}))
}

func dfs(n int, prev []int) (ans [][]int) {
	if len(prev) == n {
		return [][]int{prev}
	}
	used := make([]bool, 2*n-1)
	lCheck1 := make([]bool, 2*n-1)
	lCheck2 := make([]bool, 2*n-1)
	for i, k := range prev {
		used[k] = true
		lCheck1[i-k+n-1] = true
		lCheck2[2*n-2-i-k] = true
	}
	for k := 0; k < n; k++ {
		if !used[k] && !lCheck1[len(prev)-k+n-1] && !lCheck2[2*n-2-len(prev)-k] {
			newPrev := make([]int, len(prev)+1)
			for j, key := range prev {
				newPrev[j] = key
			}
			newPrev[len(prev)] = k
			ans = append(ans, dfs(n, newPrev)...)
		}
	}
	return ans
}
