package main

import (
	"fmt"
)

func main() {
	i := []int{5, 1, 1}
	nextPermutation(i)
	fmt.Println(i)
}

func nextPermutation(nums []int) {
	i := len(nums) - 1
	for ; i > 0 && nums[i-1] >= nums[i]; i-- {
	}
	if i > 0 {
		k := len(nums) - 1
		for ; k > i-1 && nums[k] <= nums[i-1]; k-- {
		}
		nums[i-1], nums[k] = nums[k], nums[i-1]
	}
	reverse(nums[i:])
}

func reverse(nums []int) {
	if len(nums) == 0 || len(nums) == 1 {
		return
	}

	for i := 0; i <= len(nums)/2-1; i++ {
		tmp := nums[i]
		nums[i] = nums[len(nums)-1-i]
		nums[len(nums)-1-i] = tmp
	}
	return
}
