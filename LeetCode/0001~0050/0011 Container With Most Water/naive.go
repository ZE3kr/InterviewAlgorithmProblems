package main

import "fmt"

func main() {
	fmt.Println(maxArea([]int{1, 8, 6, 2, 5, 4, 8, 3, 7}))
}

func maxArea(height []int) (max int) {
	for i, h1 := range height {
		for j := i + 1; j < len(height); j++ {
			minHeight := height[j]
			if h1 < height[j] {
				minHeight = h1
			}
			volume := (j - i) * minHeight
			if volume > max {
				max = volume
			}
		}
	}
	return max
}
