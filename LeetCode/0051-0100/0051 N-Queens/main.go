package main

import (
	"fmt"
)

func main() {
	fmt.Println(solveNQueens(7))
}

func solveNQueens(n int) (ans [][]string) {
	d := dfs(n, []int{})
	ans = make([][]string, len(d))
	for i := 0; i < len(d); i++ {
		ans[i] = make([]string, n)
		for j, k := range d[i] {
			line := make([]byte, n)
			for l := 0; l < n; l++ {
				line[l] = '.'
			}
			line[k] = 'Q'
			ans[i][j] = string(line)
		}
	}
	return ans
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
