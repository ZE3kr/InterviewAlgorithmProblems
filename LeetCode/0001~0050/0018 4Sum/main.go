package main

import (
	"fmt"
	"sort"
)

func main() {
	fmt.Println(fourSum([]int{0, -1, -3, 5, -5}, 1))
}

func fourSum(nums []int, target int) (ans [][]int) {
	length := len(nums)
	if length == 0 {
		return ans
	}

	sort.Ints(nums)
	var times int
	num := nums[0]
	optimized := []int{nums[0]}
	for i := 1; i < length; i++ {
		if nums[i] == num {
			times++
		} else {
			times = 0
			num = nums[i]
		}
		if times < 4 {
			optimized = append(optimized, nums[i])
		}
	}
	nums = optimized
	length = len(optimized)

	places := make(map[int][][2]int)
	noDeplicate := make(map[[4]int]bool)
	for i := 0; i < length-1; i++ {
		for j := i + 1; j < length; j++ {
			places[nums[i]+nums[j]] = append(places[nums[i]+nums[j]], [2]int{i, j})
		}
	}

	for k, v1 := range places {
		if v2, ok := places[target-k]; ok {
			for _, v1s := range v1 {
				for _, v2s := range v2 {
					if v1s[0] != v2s[0] && v1s[0] != v2s[1] && v1s[1] != v2s[0] && v1s[1] != v2s[1] {
						temp := []int{nums[v1s[0]], nums[v1s[1]], nums[v2s[0]], nums[v2s[1]]}
						sort.Ints(temp)
						temp4 := [4]int{temp[0], temp[1], temp[2], temp[3]}
						if _, found := noDeplicate[temp4]; !found {
							noDeplicate[temp4] = true
						}
					}
				}
			}
		}
	}
	for v := range noDeplicate {
		ans = append(ans, []int{v[0], v[1], v[2], v[3]})
	}
	return ans
}
