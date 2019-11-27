package main

import "fmt"

func main() {
	fmt.Println(permuteUnique([]int{1, 1, 2}))
}

func permuteUnique(nums []int) (ans [][]int) {
	switch len(nums) {
	case 1:
		ans = append(ans, nums)
		return ans
	case 0:
		return
	}
	duplicates := make(map[int]bool)
	for i, k := range nums {
		if _, f := duplicates[k]; f {
			continue
		} else {
			duplicates[k] = true
		}
		var input []int

		input = append(input, nums[:i]...)
		input = append(input, nums[i+1:]...)
		for _, l := range permuteUnique(input) {
			ans = append(ans, append([]int{k}, l...))
		}
	}
	return ans
}
