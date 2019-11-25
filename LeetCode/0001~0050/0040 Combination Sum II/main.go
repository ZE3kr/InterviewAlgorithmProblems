package main

import (
	"fmt"
	"reflect"
	"sort"
)

func main() {
	fmt.Println(combinationSum2([]int{10, 1, 2, 7, 6, 1, 5}, 8))
}

func combinationSum2(candidates []int, target int) (ans [][]int) {
	if target <= 0 {
		return
	}
	for i, k := range candidates {
		if target-k == 0 {
			ans = append(ans, []int{k})
		} else {
			next := combinationSum2(candidates[i+1:], target-k)

			for _, a := range next {
				a = append(a, k)
				sort.Ints(a)
				ans = append(ans, a)
			}
		}
	}
	sort.Slice(ans, func(i, j int) bool {
		if len(ans[i]) < len(ans[j]) {
			return true
		} else if len(ans[i]) > len(ans[j]) {
			return false
		}
		k := 0
		for k < len(ans[i]) && ans[i][k] == ans[j][k] {
			k++
		}
		if k == len(ans[i]) {
			return false
		}
		return ans[i][k] < ans[j][k]
	})
	var repeat []int
	var newAns [][]int
	for _, k := range ans {
		if !reflect.DeepEqual(k, repeat) {
			newAns = append(newAns, k)
			repeat = k
		}
	}
	ans = newAns
	return ans
}
