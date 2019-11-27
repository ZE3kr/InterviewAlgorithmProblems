package main

import (
	"fmt"
	"math"
	"sort"
)

func main() {
	i := []int{1, 1, 5}
	nextPermutation(i)
	fmt.Println(i)
}

func nextPermutation(nums []int) {
	if nextPermutationBool(nums) {
		return
	} else {
		sort.Ints(nums)
	}
}

func nextPermutationBool(nums []int) bool {
	switch len(nums) {
	case 0:
		return true
	case 1:
		return true
	case 2:
		if nums[0] < nums[1] {
			nums[0], nums[1] = nums[1], nums[0]
			return true
		}
		return false
	default:
		if nextPermutationBool(nums[1:]) {
			return true
		} else {
			minPlace := -1
			min := math.MaxInt32
			for i, k := range nums[1:] {
				if k < min && k > nums[0] {
					min = k
					minPlace = i
				}
			}
			if minPlace == -1 {
				return false
			}
			nums[0], nums[minPlace+1] = nums[minPlace+1], nums[0]
			sort.Ints(nums[1:])
			return true
		}
	}
}
