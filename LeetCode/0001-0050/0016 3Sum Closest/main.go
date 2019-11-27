package main

import (
	"fmt"
	"math"
)

func main() {
	fmt.Println(threeSumClosest([]int{0, 0, 0}, 1))
}

func threeSumClosest(nums []int, target int) int {
	var temp []int
	for i := 0; i < len(nums)-2; i++ {
		for k := i + 1; k < len(nums)-1; k++ {
			for j := k + 1; j < len(nums); j++ {
				temp = append(temp, nums[i]+nums[j]+nums[k]-target)
			}
		}
	}

	min := math.MaxInt32
	for _, k := range temp {
		if abs(k) < abs(min) {
			min = k
		}
	}
	return min + target
}

func abs(a int) int {
	if a < 0 {
		return -a
	}
	return a
}
