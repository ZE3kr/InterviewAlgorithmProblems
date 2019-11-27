package main

import (
	"fmt"
)

func main() {
	fmt.Println(searchRange([]int{2, 2}, 1))
}

func searchRange(nums []int, target int) []int {
	if len(nums) == 0 {
		return []int{-1, -1}
	}
	s := search(nums, 0, len(nums)-1, target)
	if s == -1 {
		return []int{-1, -1}
	}
	l, r := s-1, s+1
	for ; l >= 0 && nums[l] == target; l-- {
	}
	for ; r < len(nums) && nums[r] == target; r++ {
	}
	return []int{l + 1, r - 1}
}

func search(nums []int, l int, u int, target int) int {
	if l == u || u < 0 {
		if nums[l] != target {
			return -1
		}
		return l
	}
	if l >= len(nums) {
		if nums[u] != target {
			return -1
		}
		return u
	}
	p := (l + u) / 2
	center := nums[p]
	if center > target {
		return search(nums, l, p-1, target)
	} else if center < target {
		return search(nums, p+1, u, target)
	} else {
		return p
	}
}
