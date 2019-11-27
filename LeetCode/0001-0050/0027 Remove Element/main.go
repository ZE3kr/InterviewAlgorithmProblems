package main

import (
	"fmt"
)

func main() {
	fmt.Println(removeElement([]int{0, 0, 1, 1, 1, 2, 2, 3, 3, 4, 4, 1, 5}, 1))
}

func removeElement(nums []int, val int) (ans int) {
	for _, k := range nums {
		if k != val {
			nums[ans] = k
			ans++
		}
	}
	return ans
}
