package main

import (
	"fmt"
	"sort"
)

func main() {
	fmt.Println(fourSum([]int{-3, -2, -1, 0, 0, 1, 2, 3}, 0))
}

func fourSum(nums []int, target int) (ans [][]int) {
	length := len(nums)
	if length == 0 {
		return ans
	}

	sort.Ints(nums)
	num := nums[0]
	optimized := []int{nums[0]}
	numTimes := make(map[int]int)
	numTimes[nums[0]]++
	places := make(map[int]map[[2]int]bool)
	for i := 1; i < length; i++ {
		numTimes[nums[i]]++
		if nums[i] == num {
			if _, found := places[nums[i]*2]; !found {
				places[nums[i]*2] = make(map[[2]int]bool)
			}
			places[nums[i]*2][[2]int{nums[i], nums[i]}] = true
		} else {
			num = nums[i]
			optimized = append(optimized, nums[i])
		}
	}
	nums = optimized
	length = len(optimized)

	for i := 0; i < length-1; i++ {
		for j := i + 1; j < length; j++ {
			if _, found := places[nums[i]+nums[j]]; !found {
				places[nums[i]+nums[j]] = make(map[[2]int]bool)
			}
			places[nums[i]+nums[j]][[2]int{nums[i], nums[j]}] = true
		}
	}

	noDuplicate := make(map[[4]int]bool)
	for n, v1 := range places {
		if v2, found := places[target-n]; found {
			for v1s := range v1 {
				for v2s := range v2 {
					//fmt.Println(v1s, v2s)
					var tempNums [4]int // 由于 v1s 和 v2s 已经有序，这里用归并排序
					l, m := 0, 0
					for i := 0; i < 2; i++ {
						if v1s[l] > v2s[m] {
							tempNums[i] = v2s[m]
							m++
						} else {
							tempNums[i] = v1s[l]
							l++
						}
					}
					if m == 0 {
						tempNums[2] = v2s[m]
						tempNums[3] = v2s[m+1]
					} else if l == 0 {
						tempNums[2] = v1s[l]
						tempNums[3] = v1s[l+1]
					} else {
						if v1s[l] > v2s[m] {
							tempNums[2] = v2s[m]
							tempNums[3] = v1s[l]
						} else {
							tempNums[2] = v1s[l]
							tempNums[3] = v2s[m]
						}
					}
					//fmt.Println(tempNums)
					if tempNums[0] == tempNums[3] && numTimes[tempNums[0]] < 4 {
						continue
					}

					if tempNums[0] == tempNums[2] && numTimes[tempNums[0]] < 3 {
						continue
					}
					if tempNums[1] == tempNums[3] && numTimes[tempNums[1]] < 3 {
						continue
					}

					if tempNums[0] == tempNums[1] && numTimes[tempNums[0]] < 2 {
						continue
					}
					if tempNums[1] == tempNums[2] && numTimes[tempNums[1]] < 2 {
						continue
					}
					if tempNums[2] == tempNums[3] && numTimes[tempNums[2]] < 2 {
						continue
					}
					noDuplicate[tempNums] = true
				}
			}
		}
	}

	for k := range noDuplicate {
		ans = append(ans, []int{k[0], k[1], k[2], k[3]})
	}
	return ans
}
