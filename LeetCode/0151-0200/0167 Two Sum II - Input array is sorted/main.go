package main

import "fmt"

func main() {
	fmt.Println(twoSum([]int{2, 7, 11, 15}, 9))
}

func twoSum(nums []int, target int) []int {
	places := make(map[int]int)
	for i, num := range nums {
		places[num] = i
	}
	for i, num := range nums {
		if j, ok := places[target-num]; ok && j > i {
			return []int{i + 1, j + 1}
		}
	}
	return nil
}
