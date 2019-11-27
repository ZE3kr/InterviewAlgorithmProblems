package main

import (
	"fmt"
)

func main() {
	fmt.Println(removeDuplicates([]int{0, 0, 1, 1, 1, 2, 2, 3, 3, 4, 4, 5}))
}

func removeDuplicates(nums []int) (ans int) {
	length := len(nums)
	if length == 0 {
		return 0
	}

	num := nums[0]
	ans++
	for i := 1; i < length; i++ {
		if nums[i] != num {
			num = nums[i]
			nums[ans] = num
			ans++
		}
	}
	return ans
}
