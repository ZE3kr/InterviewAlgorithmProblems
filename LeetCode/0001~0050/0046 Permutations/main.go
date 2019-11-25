package main

import "fmt"

func main() {
	fmt.Println(permute([]int{1, 2, 3}))
}

func permute(nums []int) (ans [][]int) {
	switch len(nums) {
	case 1:
		ans = append(ans, nums)
		return ans
	case 0:
		return
	}
	for i, k := range nums {
		var input []int

		input = append(input, nums[:i]...)
		input = append(input, nums[i+1:]...)
		for _, l := range permute(input) {
			ans = append(ans, append([]int{k}, l...))
		}
	}
	return ans
}
