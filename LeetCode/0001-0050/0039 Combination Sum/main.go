package main

import (
	"fmt"
	"reflect"
	"sort"
)

func main() {
	fmt.Println(combinationSum([]int{7, 3, 2}, 18))
}

func combinationSum(candidates []int, target int) (ans [][]int) {
	if target <= 0 {
		return
	}
	for _, k := range candidates {
		if target-k == 0 {
			ans = append(ans, []int{k})
		} else {
			next := combinationSum(candidates, target-k)
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
